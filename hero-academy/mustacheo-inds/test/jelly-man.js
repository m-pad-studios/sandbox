var jelly = 0;
var jellyQueenGrowth = 10 + "%";
var rsw_powered = {};
document.getElementById("restorePower").style.visibility = "hidden";
rsw_powered["augmented-ui"] = true;

var gels = function () {

  var elm = document.querySelector("#jelly");
if(this.jelly === 100) {
  elm.innerHTML = jelly;
}
};


function jellyMan() {

  $("#jelly-header").slideToggle();

}

function powerShip() {

  if (jelly === 0) {
    
    document.getElementById("restorePower").style.visibility = "hidden";
    var elem = document.getElementById("myBar");
    var height = 0;
    var id = setInterval(frame, 100);
    function frame() {
      if (height >= 0 && height < 100) {
              height++;
        elem.style.height = (100 - height) + '%';
        elem.innerHTML = height * 1 + '%';
      } 
    }
  }
  else {
    clearInterval(id);
  }
}

function gatherJellies() {
  if (this.jelly === 100) {
    document.getElementById("restorePower").style.visibility = "visible";
    this.jelly = 0;
    this.jellyQueenGrowth = 10 + "%";
    document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;
    document.getElementById("jelly").innerHTML = this.jelly;
    var height = 38.7333;
    var elem = document.getElementById("myBar");
    var id = setInterval(frame, 100);
    function frame() {
      if (height === 38.7333) {
        height--;
        elem.style.height = (100 + height) + "%";
        elem.innerHTML = 0 + "%";
      } 
    }
  }
  else {
    customAlert("You cannot gather jelly until the Queen is ready!","jelly-alert-msg");
   
  }

}

function depositJellies() {
  if(this.jelly === 100) {
    customAlert("You cannot feed the Queen more than 100 jelly!", "jelly-alert-msg");
 
  }
  else{
  this.jelly += 5;
  document.getElementById("jelly").innerHTML = this.jelly;
  }
}

function customAlert(msg, id) {
  var closeBtn = document.createElement("button");
  closeBtn.innerHTML = "X";
  closeBtn.id = "closeBtn";
  closeBtn.onclick = function (){ closeAlert(); }
  document.getElementById(id).innerHTML = msg;
  document.getElementById(id).style.visibility = "visible";
  document.getElementById("alert-box").style.visibility = "visible";
  document.getElementById("alert-box").appendChild(closeBtn);

  checkQueenStatus();
}


// CONTROLS QUEENS SIZE DYNAMICALLY
function checkQueenStatus() {
  var start = true;
  while (start) {
    if (this.jellyQueenGrowth === 10 + "%") {

      this.jellyQueenGrowth = 20 + "%";
      document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;

      break;
    }
    if (this.jellyQueenGrowth === 20 + "%") {

      this.jellyQueenGrowth = 30 + "%";
      document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;

      break;
    }


    if (this.jellyQueenGrowth === 30 + "%") {

      this.jellyQueenGrowth = 40 + "%";
      document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;

      break;
    }


    if (this.jellyQueenGrowth === 40 + "%") {

      this.jellyQueenGrowth = 50 + "%";
      document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;

      break;
    }


    if (this.jellyQueenGrowth === 50 + "%") {

      this.jellyQueenGrowth = 60 + "%";
      document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;

      break;
    }

    if (this.jellyQueenGrowth === 60 + "%") {

      this.jellyQueenGrowth = 70 + "%";
      document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;
;
      break;
    }

    if (this.jellyQueenGrowth === 70 + "%") {

      this.jellyQueenGrowth = 80 + "%";
      document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;

      break;
    }

    if (this.jellyQueenGrowth === 80 + "%") {

      this.jellyQueenGrowth = 90 + "%";
      document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;

      break;
    }

    if (this.jellyQueenGrowth === 90 + "%") {

      this.jellyQueenGrowth = 100 + "%";
      document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;

      break;
    }
    if (this.jellyQueenGrowth === 100 + "%") {
      alert("The Queen Jelly is about to explode!!!");
      start = false;
      this.jellyQueenGrowth = 100 + "%";
      document.getElementById("jelly-wrapper").style.width = this.jellyQueenGrowth;
  
      break;
    }
  }
}

function closeAlert() {
  
document.getElementById("alert-box").style.visibility = "hidden";
document.getElementById("jelly-alert-msg").style.visibility = "hidden";
document.getElementById("alert-box").removeChild(document.getElementById("closeBtn"));
}