"use strict";


$("[data-trigger]").on("click", function(e){
    e.preventDefault();
    e.stopPropagation();
    var offcanvas_id =  $(this).attr('data-trigger');
    $(offcanvas_id).toggleClass("show");
    $('body').toggleClass("offcanvas-active");
    $(".screen-overlay").toggleClass("show");
}); 

$(".btn-close, .screen-overlay").click(function(e){
    $(".screen-overlay").removeClass("show");
    $(".mobile-offcanvas").removeClass("show");
    $("body").removeClass("offcanvas-active");
}); 

function functionAlert(msg, myYes) {
   
    var confirmBox = $("#confirm");
 
    confirmBox.find(".message").text(msg);
    confirmBox.find(".yes").unbind().click(function() {
       confirmBox.hide();
    });
    confirmBox.find(".yes").click(myYes);
    confirmBox.show();
 }
function alienInfo(msg, myYes){
    

    var confirmBox = $("#info");
 
    confirmBox.find(".msg").text(msg);
    confirmBox.find(".yes").unbind().click(function() {
       confirmBox.hide();
    });
    confirmBox.find(".yes").click(myYes);
    confirmBox.show();
}
 function alertSystemRestored(msg, myYes) {

    var confirmBox = $("#restored");
 
    confirmBox.find(".msg").text(msg);
    confirmBox.find(".yes").unbind().click(function() {
       confirmBox.hide();
    });
    confirmBox.find(".yes").click(myYes);
    confirmBox.show();
 }
function openHeroId() {
  
    
        $(".profile-row").slideToggle("slow");
      
}

function closeNavSys(){
 
    $(".id-card-wrapper").slideToggle("slow");
 
}

function powerOn() {
    myShip.increasePowerSupply();
    alertSystemRestored();
    document.getElementById("on-switch").style.color = "green";
    document.getElementById("revealNav").style.color = "green";
    document.getElementById("on-switch").style.visibility = "hidden";
    
}

// OPENING SETTINGS 
function openSettings() {
document.getElementById("power").innerHTML = myShip.getPowerSupply();
document.getElementById("life").innerHTML = myShip.getLifeLine() + "%";
document.getElementById("revealNav").style.color = "red";
document.getElementById("on-switch").style.color = "yellow";

closeNavSys();
}

function revealNav(){
    
    powerGrid();
    if(document.getElementById("on-switch").style.color === "yellow"){
       functionAlert();
    }
    else if(document.getElementById("on-switch").style.color === "green"){
    console.log("NAV SYSTEM ONLINE!");
    closeNavSys();
    document.getElementById("badge-id").style.alignSelf = "top";
    document.getElementById("nav-container").style.visibility = "visible";
    }
}


function powerGrid() {
    
   
        myShip.decreasePower();
        document.getElementById("power").innerHTML = myShip.getPowerSupply();
        lockShip();
    
}

function lockShip() {
    if(myShip.getPowerSupply() === 0) {
        functionAlert("OUT OF POWER!");
        document.getElementById("on-switch").style.visibility = "visible";
        document.getElementById("nav-container").style.visibility = "hidden";
        openSettings();
    }
}

// Ship Obj
class Ship {
    constructor(powerSupply, lifeLine){
        
        this.lifeLine = lifeLine;
        this.powerSupply = powerSupply;
    }

    decreasePower(){
        
        
        if(this.powerSupply > 0){
            this.powerSupply = this.powerSupply - 10;
        }
        else{
            this.powerSupply = 0;
        return this.powerSupply;
        }
    }
    getPowerSupply(){
return this.powerSupply;
    }

    getLifeLine(){
        return this.lifeLine;
    }

    increasePowerSupply(){
        if(this.powerSupply === 100){
            alertSystemRestored();
        }
        
        return this.powerSupply += 50;
        
    }
}

const myShip = new Ship(100, 100);
openSettings();
