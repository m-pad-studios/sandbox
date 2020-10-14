<template>
  <section >
    <div class="hero">
      <div class="hero-inner" id="marginz">
        <div class=" hero-title">
          <h1 class="text-light title font-2">
            Software Developer, CS Aficionado
          </h1>
          <img alt="Vue" class="rounded-circle" src="@/assets/space-mike.jpg" />
          <span class="text-light" id="name">
            <mark class="mk"> Name: Mike Parker</mark>
          </span>
          <div class="text-light" id="bucket-list">
           
          </div>

          <div class="mini-resume text-light">
            <h3><u>Nutshell Resume</u></h3>
            <ul>
              <li>
                <span>
                  <em
                    >Skills: HTML5, CSS, JS, Vue.js. ASP.NET, <br />
                    Node, Express, Django, Python.</em
                  >
                </span>
              </li>
              <li>
                <span>
                  <em>Full stack web development with AWS Cloud.</em>
                </span>
              </li>
              <li>
                <span>
                  <em>Years of XP: 1</em>
                </span>
              </li>
            </ul>
          </div>


          <br>
          <br>
          <div class="text-light">
          <p>Click the arrow below to find out more</p>
          </div>
          <br id="barz">
          <div class=" text-light">
             <a href="#" class="sd" id="arr-down">&#8595;</a>    
          </div>
    
         
        </div>
      </div>

    </div>
  </section>
</template>

<script lang="ts">
import $ from "jquery";

export default {
  mounted() {
    $(".sd").click(function() {
      $(".hero, .content").addClass("scrolled");
    });
  },
};
</script>

<style lang="css" scoped>
#marginz{
  padding-bottom: 0px;

}

#barz {
  margin-bottom: 900px;
}

#arr-down {
  font-size: 2rem;
 padding-bottom: 800px;  

}

#name {
  color: white;
  margin-left: 10px;
  font-size: 1em;

}

.mk {
  color: white;
  background-color: rgba(66, 52, 52, 0.833);
  border-radius: 55%;

}

#bucket-list {
  margin-top: 10px;
  font-size: 1em;

}
.card {
  font-size: 1em;
  color: rgba(255, 255, 255, 0.267);
  background-color: rgba(52, 52, 66, 0.933);
  margin-top: 10px;
  margin-left: 100px;
  width: 50%;
  height: 100vh;
}

.mini-resume {
  margin-right: 75px;
  margin-left: 30px;

    background-color: rgba(107, 107, 112, 0.959);
}

body {
  font-family: "josefin sans";
  font-size: 16px;
 
}

.hero {
  height: 100vh;
  width: 100%;
  position: fixed;

  transition: all 1.6s cubic-bezier(0.86, 0, 0.07, 1);
}

.hero.scrolled {
  transform: translate3d(0, -100%, 0) scale(0.75);
  opacity: 0;
}
.hero-inner { 
 
  background-size: cover;
  background-position: center;
  display: table;
  width: 100%;
  height: 100vh;
  position: fixed;
  top: 0;
}
.hero-title {
  background-color: rgba(0, 0, 0, 0.8);
  display: table-cell;
  vertical-align: middle;
  text-align: center;
}
h1,
h2,
h3,
h4,
h5,
h6 {
  font-family: montserrat;
}
.font-2 {
  font-family: "josefin sans";
  font-weight: 700;
}
.title {
  font-size: 1.5em;
  letter-spacing: 0.3em;
  text-transform: uppercase;
}
.text-light {
  color: #fff;
}
.font-alt {
  font-family: "georgia";
  font-style: italic;
  color: #667;
}
.hero {
  overflow: hidden;
  z-index: 1;
}
.content {
  position: relative;
  background-color: #fff;
  border-top: 10px solid black;
  padding: 0;
  margin: 0;
  transition: all 1.6s cubic-bezier(0.86, 0, 0.07, 1);
  transform: translate3d(0, 20px, 0) scale(0.75);
  opacity: 0;
}
.content.scrolled {
  transform: translate3d(0, 0, 0) scale(1);
  opacity: 1;
}
.sd {
  color: #fff;
  position: absolute;
  bottom: 20px;
  left: 50%;
  transform: translateX(-50%);
}
.sd:hover,
.sd:focus {
  color: #fff;
  opacity: 0.7;
  text-decoration: none;
}
</style>
