import Vue from 'vue';
import VueRouter from 'vue-router';

Vue.use(VueRouter);
let router = new VueRouter({
    routes: [
        {path:'/', name:'Landing', component: () =>import('./components/Lander')},
        {path:'/Projects', name:'Projects', component: () =>import('./components/Projects')},
    ]
});
export default router;