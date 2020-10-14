const flag = true;

var navControls = function () {
  $(document).ready(function () {
    $(".slide-toggle").click(function () {
      $(".box").slideToggle();
    });
  });
};

var login = function () {
  $(document).ready(function () {
    $(".slide-toggle").click(function () {
      $(".box").animate({
        width: "toggle",
      });
    });
  });
};

var openNav = function () {
  document.getElementById("welcome-card").style.visibility = "hidden";
  document.getElementById("nav").style.visibility = "visible";
  $(".box").slideToggle();
  $("#welcome-card").remove();
};

var closeNav = function () {
 
  document.getElementById("nav").style.visibility = "hidden";
  $(".box").slideToggle();
};

var bars = function () {
  var elm = document.querySelector("#progress");
  setInterval(function () {
    if (!elm.innerHTML.match(/100%/gi)) {
      elm.innerHTML = parseInt(elm.innerHTML) + 1 + "%";
    } else {
      clearInterval();
    }
  }, 30);
};

var power = function () {
  var elm = document.querySelector("#power");
  setInterval(function () {
    if (!elm.innerHTML.match(/100%/gi)) {
      elm.innerHTML = parseInt(elm.innerHTML) + 1 + "%";
    } else {
      clearInterval();
    }
  }, 30);
};

var life = function () {
  var elm = document.querySelector("#life");
  setInterval(function () {
    if (!elm.innerHTML.match(/100%/gi)) {
      elm.innerHTML = parseInt(elm.innerHTML) + 1 + "%";
    } else {
      clearInterval();
    }
  }, 30);
};

var blood = function () {
  var elm = document.querySelector("#blood");
  setInterval(function () {
    if (!elm.innerHTML.match(/100%/gi)) {
      elm.innerHTML = parseInt(elm.innerHTML) + 1 + "%";
    } else {
      clearInterval();
    }
  }, 30);
};

var hunger = function () {
  var elm = document.querySelector("#hunger");
  setInterval(function () {
    if (!elm.innerHTML.match(/100%/gi)) {
      elm.innerHTML = parseInt(elm.innerHTML) + 1 + "%";
    } else {
      clearInterval();
    }
  }, 30);
};
// hunger();
 //blood();
 life();
 power();
// bars();
// closeNav();

/* Custom button code pen [NOT MY CODE] will update author. */

class SFButton {
  instance;

  constructor() {
    if (!SFButton.instance) SFButton.instance = this;
    return SFButton.instance;
  }

  initButtons() {
    document.querySelectorAll(".js-sfbtn").forEach(this.createButton);
  }

  createButton(btn) {
    if (!btn.classList.contains("js-sfbtn")) exit;
    const btnContent = btn.innerHTML;

    const btnTail = document.createElement("div");
    btnTail.classList.add("btn-tail");

    const btnBody = document.createElement("div");
    btnBody.classList.add("btn-body");
    btnBody.innerHTML = `<p>${btnContent}</p>`;

    btn.innerHTML = "";
    btn.classList.add("btn-wrapper");
    btn.classList.remove("js-sfbtn");
    btn.appendChild(btnTail);
    btn.appendChild(btnBody);

    btn.style.setProperty("--bg-color", btn.dataset.bgColor);
    btn.style.setProperty("--font-color", btn.dataset.fontColor);
    btn.style.setProperty("--bg-color-hovered", btn.dataset.bgColorHovered);
    btn.style.setProperty("--font-color-hovered", btn.dataset.fontColorHovered);
  }

  formatLink(
    content,
    href,
    colorBG,
    colorBGHovered,
    colorFont,
    colorFontHovered
  ) {
    const link = document.createElement("a");
    link.dataset.bgColor = colorBG;
    link.dataset.fontColor = colorFont;
    link.dataset.bgColorHovered = colorBGHovered;
    link.dataset.fontColorHovered = colorFontHovered;
    link.innerHTML = content;
    link.href = href;
    link.classList.add("js-sfbtn");
    return link;
  }
}

/*** JavaScript integration ***/
// First get the SFButton instance
const sfButton = new SFButton();

// There is two way to use SFButton builder

// When the page has been build ...
sfButton.initButtons();

// ... And to add a new button asynchronously
// addALinkAsynchronously();

// Those are the functions used to create the asynchronous link
// async function addALinkAsynchronously() {
//   const linkData = await fetchDataFromAnAPIOrWhatEver();
//   const link = sfButton.formatLink(
//     linkData.content,
//     linkData.href,
//     "#fffff0",
//     "#c4afff",
//     "#000000",
//     "#000000"
//   );
//   document.querySelector("#exploration").appendChild(link);
//   sfButton.createButton(link);
// }

// function fetchDataFromAnAPIOrWhatEver() {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       resolve({
//         content: 
//           "<span onclick='explore()' style='width: 50%;'>Explore</span> <span style='font-size: 0.7rem; margin-left: 5px;' id='logout' onclick='explore()''>Explore</span>",
//         href:
//         "#",

      
//       });
//     }, 3000);
//   });
// }

function explore() {
  $(".sidebar-left").slideToggle();
  $(".main-circle").slideToggle();
  $(".status-panel").slideToggle();
  $(".sidebar-right").slideToggle();
}

/* Functions that need to move out of this file to separate  */

function joinAcademy() {
  document.getElementById("flames").style.visibility = "visible";
    }

function hideNav() {
  $(".navvy").slideToggle();
}

function hideStatusBars() {
  $(".statusBars").slideToggle();
}

function closeInfo() {
  console.log("in here!!!!!!!!!");
  $("#info_card").slideToggle();
}

function closeMainCard() {
  $("#main_card").slideToggle();
}

function openSettings() {
  document.getElementById("loginAlert").style.visibility = "hidden";
 // hideNav();
  hideStatusBars();
closeMainCard();
}

function openShipConsole() {  
  document.getElementById("main_card").style.visibility = "visible";
  openSettings();

}

if (flag === true){
  flag = false;
  openSettings();
}

