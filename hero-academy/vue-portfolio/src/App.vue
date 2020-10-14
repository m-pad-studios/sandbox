<template > 
  <div id="app">
 
    <navigation />
   <router-view></router-view> 
   <video autoplay muted loop id="myVideo">
  <source src="@/assets/clouds.mp4" type="video/mp4">
</video>
   <portfolio-deck />
  
   <Footer/>   
  
  
</div>

  
</template>

<script>


import Navigation from './components/includes/navigation.vue';
import Footer from './components/includes/footer.vue';
import PortfolioDeck from './components/includes/portfolio-deck.vue';

export default {
  name: 'App',
  components: {
    Navigation,
    Footer,
    PortfolioDeck
  }
}
</script>

<style>


#app {
  background-image: url("./assets/clouds.mp4");
  background-repeat: none;
  background-size: cover;
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
 /* 
 * Add BG color here.
 */
 background-color: rgba(0, 0, 0, 0.835);

 overflow-x: hidden;
  right: 0;
  
height: 100vh;
}
</style>
