import Vue from 'vue';
import App from './App.vue';
import $ from 'jquery';
import router from './router';


Vue.config.productionTip = false;



new Vue({
  render: h => h(App),
  router,
  $
}).$mount('#app')
