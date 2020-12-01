function preload(){
  const queryString = window.location.search;
  const urlParams = new URLSearchParams(queryString);
  if(urlParams.has("spec")){
    var type = urlParams.get("spec");
    if(type == "Hoy")
      today();
    else if(type == "Semana")
      week();
    else if(type == "Mes")
      month();
    else if(type == "Siempre")
      alTime();
    else if(type == "Personalizado"){
      var isRange = urlParams.get("rango");
      var start = urlParams.get("inicio");
      if(isRange == "true"){
        var fin = urlParams.get("fin");
        range(start,fin);
      }
      else
        day(start);
    }
  }
  else
    today();
}
function navActive(index){
  var navs  = document.getElementsByClassName("nav-item");
  var elemento = navs[index];
  elemento.className = "nav-item active"
}
function today(){
  var tit  =document.getElementById("Titulo");
  tit.innerHTML = "EL DÍA DE HOY";

  var inner = document.getElementById("inner");
  var horas = document.createElement("DIV");
  horas.className = "carousel-item active";
  horas.id = "horas";
  inner.appendChild(horas);

  var hoy = new Date();
  var titulo = dayCode(hoy.getDay())+" "+
              hoy.getDate()+" de "+
              monthCode(hoy.getMonth())+" de "+
              hoy.getFullYear();
  var xHora = ["8:00","9:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00"];
  var yHora = [0,0,0,0,0,0,0,0,0,0,0,0,0];

  const db = firebase.database().ref('/Datos');
  db.once('value').then(function(dataSnapshot) {
    var registros = dataSnapshot.val();
    
    for (const key in registros) {
      const element = registros[key];
      var fecha = element["Fecha"];
      var time = element["Time"];

      fecha = fecha.split("/");
      time = time.split(":");
      dbDate = new Date(fecha[2],fecha[1]-1,fecha[0],time[0]);
      if(dbDate.toLocaleDateString() == hoy.toLocaleDateString()){
        hora = dbDate.getHours() - 8;
        yHora[ hora ]++;
      }
    }
    var trace1 = {
        x: xHora,
        y: yHora,
        type: 'bar',
        text: xHora,
        marker: {
          color: '#A4BEFA',
        }
      };
      
      var data = [trace1];
      barras(data,titulo,"horas");
  });
}
function day(start){
  navActive(3);
  
  var inner = document.getElementById("inner");
  var horas = document.createElement("DIV");
  horas.className = "carousel-item";
  horas.id = "horas";
  inner.appendChild(horas);
  
  start = start.split("-");
  var hoy = new Date(start[0],start[1]-1,start[2]);
  var titulo = dayCode(hoy.getDay())+" "+
              hoy.getDate()+" de "+
              monthCode(hoy.getMonth())+" de "+
              hoy.getFullYear();
  var tit  = document.getElementById("Titulo");
  tit.innerHTML = titulo;
  var xHora = ["8:00","9:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00"];
  var yHora = [0,0,0,0,0,0,0,0,0,0,0,0,0];

  const db = firebase.database().ref('/Datos');
  db.once('value').then(function(dataSnapshot) {
    var registros = dataSnapshot.val();
    
    for (const key in registros) {
      const element = registros[key];
      var fecha = element["Fecha"];
      var time = element["Time"];

      fecha = fecha.split("/");
      time = time.split(":");
      dbDate = new Date(fecha[2],fecha[1]-1,fecha[0],time[0]);
      if(dbDate.toLocaleDateString() == hoy.toLocaleDateString()){
        hora = dbDate.getHours() - 8;
        yHora[ hora ]++;
      }
    }
    var trace1 = {
        x: xHora,
        y: yHora,
        type: 'bar',
        text: xHora,
        marker: {
          color: '#A4BEFA',
        }
      };
      var data = [trace1];
      barras(data,titulo,"horas");
  });
}
function range(start,end){
  navActive(3);
  var tit  = document.getElementById("Titulo");
  tit.innerHTML = "RANGO PERSONALIZADO";

  var inner = document.getElementById("inner");
  var dias = document.createElement("DIV");
  var horas = document.createElement("DIV");
  dias.className = "carousel-item active";
  horas.className = "carousel-item";
  dias.id = "dias";
  horas.id = "horas";
  inner.appendChild(dias);
  inner.appendChild(horas);

  start = start.split("-");
  end = end.split("-");
  var fin = new Date(end[0],end[1]-1,end[2],23,59,59);
  var inicio = new Date(start[0],start[1]-1,start[2]);
  var titulo = dayCode(inicio.getDay()) + " " + (inicio.getDate()) +
              " a " + 
              dayCode(fin.getDay()) + " " + fin.getDate();

  var xHoras = ["8:00","9:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00"];
  var xDias = [dayCode(fin.getDay()+1),dayCode(fin.getDay()+2),dayCode(fin.getDay()+3),dayCode(fin.getDay()+4),dayCode(fin.getDay()+5),dayCode(fin.getDay()+6),dayCode(fin.getDay())];
  var yHoras = [0,0,0,0,0,0,0,0,0,0,0,0,0];
  var yDias = [0,0,0,0,0,0,0];


  const db = firebase.database().ref('/Datos');
  db.once('value').then(function(dataSnapshot) {
    var registros = dataSnapshot.val();

    for (const key in registros) {
      const element = registros[key];
      var fecha = element["Fecha"];
      var time = element["Time"];

      fecha = fecha.split("/");
      time = time.split(":");
      dbDate = new Date(fecha[2],fecha[1]-1,fecha[0],time[0]);
      if(dbDate >= inicio && dbDate <= fin){
        yDias[ dbDate.getDay() ]++;
        hora = dbDate.getHours() - 8;
        yHoras[ hora ]++;
      }
    }

    var porDias = {
        x: xDias,
        y: yDias,
        type: 'bar',
        text: xDias,
        marker: {
          color: '#A4BEFA',
        }
      };
    var porHoras = {
        x: xHoras,
        y: yHoras,
        type: 'bar',
        text: xHoras,
        marker: {
          color: '#A4BEFA',
        }
      };

      var porDias = [porDias];
      barras(porDias,titulo,"dias");
      var porHoras = [porHoras];
      barras(porHoras,titulo,"horas");
    });
}
function week(){
  navActive(0);
  var tit  = document.getElementById("Titulo");
  tit.innerHTML = "ESTA SEMANA";
  var inner = document.getElementById("inner");
  var dias = document.createElement("DIV");
  var horas = document.createElement("DIV");
  dias.className = "carousel-item active";
  horas.className = "carousel-item";
  dias.id = "dias";
  horas.id = "horas";
  inner.appendChild(dias);
  inner.appendChild(horas);

  var fin = new Date();
  var inicio = new Date(fin.getFullYear(),fin.getMonth(),fin.getDate()-6);
  var titulo = dayCode(inicio.getDay()) + " " + (inicio.getDate()) +
              " a " + 
              dayCode(fin.getDay()) + " " + fin.getDate();
  
  var xHoras = ["8:00","9:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00"];
  var xDias = [dayCode(fin.getDay()+1),dayCode(fin.getDay()+2),dayCode(fin.getDay()+3),dayCode(fin.getDay()+4),dayCode(fin.getDay()+5),dayCode(fin.getDay()+6),dayCode(fin.getDay())];
  var yHoras = [0,0,0,0,0,0,0,0,0,0,0,0,0];
  var yDias = [0,0,0,0,0,0,0];

  moveRight = 7 - inicio.getDay();

  const db = firebase.database().ref('/Datos');
  db.once('value').then(function(dataSnapshot) {
    var registros = dataSnapshot.val();
    
    for (const key in registros) {
      const element = registros[key];
      var fecha = element["Fecha"];
      var time = element["Time"];

      fecha = fecha.split("/");
      time = time.split(":");
      dbDate = new Date(fecha[2],fecha[1]-1,fecha[0],time[0]);
      if(dbDate >= inicio && dbDate <= fin){
        index = (dbDate.getDay() + moveRight)%7;
        yDias[ index ]++;
        hora = dbDate.getHours() - 8;
        yHoras[ hora ]++;
      }
    }

    var porDias = {
        x: xDias,
        y: yDias,
        type: 'bar',
        text: xDias,
        marker: {
          color: '#A4BEFA',
        }
      };
    var porHoras = {
        x: xHoras,
        y: yHoras,
        type: 'bar',
        text: xHoras,
        marker: {
          color: '#A4BEFA',
        }
      };

      var porDias = [porDias];
      barras(porDias,titulo,"dias");
      var porHoras = [porHoras];
      barras(porHoras,titulo,"horas");
  });
}
function month(){
  navActive(1);
  var tit  = document.getElementById("Titulo");
  tit.innerHTML = "ESTE MES";
  
  var inner = document.getElementById("inner");
  var dias = document.createElement("DIV");
  var horas = document.createElement("DIV");
  dias.className = "carousel-item active";
  horas.className = "carousel-item";
  dias.id = "dias";
  horas.id = "horas";
  inner.appendChild(dias);
  inner.appendChild(horas);

  var fin = new Date();
  var inicio = new Date(fin.getFullYear(),fin.getMonth()-1,fin.getDate());
  var titulo = dayCode(inicio.getDay()) + " " + (inicio.getDate()) + " de " + monthCode(inicio.getMonth()) + 
              " a " + 
              dayCode(fin.getDay()) + " " + fin.getDate() + " de " + monthCode(fin.getMonth());
  
  var xHoras = ["8:00","9:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00"];
  var xDias = [dayCode(0),dayCode(1),dayCode(2),dayCode(3),dayCode(4),dayCode(5),dayCode(6)];
  var yHoras = [0,0,0,0,0,0,0,0,0,0,0,0,0];
  var yDias = [0,0,0,0,0,0,0];

  const db = firebase.database().ref('/Datos');
  db.once('value').then(function(dataSnapshot) {
    var registros = dataSnapshot.val();
    
    for (const key in registros) {
      const element = registros[key];
      var fecha = element["Fecha"];
      var time = element["Time"];

      fecha = fecha.split("/");
      time = time.split(":");
      dbDate = new Date(fecha[2],fecha[1]-1,fecha[0],time[0]);
      
      if(dbDate >= inicio && dbDate <= fin){
        yDias[ dbDate.getDay() ]++;
        hora = dbDate.getHours() - 8;
        yHoras[ hora ]++;
      }
    }

    var porDias = {
        x: xDias,
        y: yDias,
        type: 'bar',
        text: xDias,
        marker: {
          color: '#A4BEFA',
        }
      };
    var porHoras = {
        x: xHoras,
        y: yHoras,
        type: 'bar',
        text: xHoras,
        marker: {
          color: '#A4BEFA',
        }
      };

      var porDias = [porDias];
      barras(porDias,titulo,"dias");
      var porHoras = [porHoras];
      barras(porHoras,titulo,"horas");
  });
}
function alTime(){
  navActive(2);
  var tit  = document.getElementById("Titulo");
  tit.innerHTML = "TODO EL TIEMPO";
  
  var inner = document.getElementById("inner");
  var dias = document.createElement("DIV");
  var horas = document.createElement("DIV");
  dias.className = "carousel-item active";
  horas.className = "carousel-item";
  dias.id = "dias";
  horas.id = "horas";
  inner.appendChild(dias);
  inner.appendChild(horas);
  
  var titulo = "";
  
  var xHoras = ["8:00","9:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00"];
  var xDias = [dayCode(0),dayCode(1),dayCode(2),dayCode(3),dayCode(4),dayCode(5),dayCode(6)];
  var yHoras = [0,0,0,0,0,0,0,0,0,0,0,0,0];
  var yDias = [0,0,0,0,0,0,0];

  const db = firebase.database().ref('/Datos');
  db.once('value').then(function(dataSnapshot) {
    var registros = dataSnapshot.val();

    for (const key in registros) {
      const element = registros[key];
      var fecha = element["Fecha"];
      var time = element["Time"];

      fecha = fecha.split("/");
      time = time.split(":");
      dbDate = new Date(fecha[2],fecha[1]-1,fecha[0],time[0]);

      yDias[ dbDate.getDay() ]++;
      hora = dbDate.getHours() - 8;
      yHoras[ hora ]++;

    }

    var porDias = {
        x: xDias,
        y: yDias,
        type: 'bar',
        text: xDias,
        marker: {
          color: '#A4BEFA',
        }
      };
    var porHoras = {
        x: xHoras,
        y: yHoras,
        type: 'bar',
        text: xHoras,
        marker: {
          color: '#A4BEFA',
        }
      };

      var porDias = [porDias];
      barras(porDias,titulo,"dias");
      var porHoras = [porHoras];
      barras(porHoras,titulo,"horas");
  });
}

function barras(data,titulo,place){
  var layout = {
    title: titulo,
    font:{
      family: 'Raleway, sans-serif',
      color: "#FFF"
    },
    showlegend: false,
    xaxis: {
      tickangle: -45
    },
    yaxis: {
      gridcolor: "#d9d9d8",
      zeroline: false,
      gridwidth: 0.5
    },
    plot_bgcolor:"#132937",
    paper_bgcolor:"#132937",
    bargap :0.05
  };
  Plotly.plot(place, data, layout);
}
function dayCode(day){
  day %= 7;
  if(day == 0) return "Domingo";
  if(day == 1) return "Lunes";
  if(day == 2) return "Martes";
  if(day == 3) return "Miercoles";
  if(day == 4) return "Jueves";
  if(day == 5) return "Viernes";
  if(day == 6) return "Sabado";
}
function monthCode(month){
  month %= 12;
  if(month == 0) return "Enero";
  if(month == 1) return "Febrero";
  if(month == 2) return "Marzo";
  if(month == 3) return "Abril";
  if(month == 4) return "Mayo";
  if(month == 5) return "Junio";
  if(month == 6) return "Julio";
  if(month == 7) return "Agosto";
  if(month == 8) return "Septiembre";
  if(month == 9) return "Octubre";
  if(month == 10) return "Noviembre";
  if(month == 11) return "Diciembre";
}
preload();