<template>
    <section class="protfolio">
        <hr id="barz">
            <h1 class="text-light"><u>Portfolio</u></h1>
            <p class="text-light">These are suppose to be sample projects</p>
            <div class="container">
                <div class="row">
                    <div class="col-md-4">
                            <div class="card">
                                <div class="card-head">
                                    <img alt="Vue logo"
                                      class="rounded-circle img-custome" 
            src="@/assets/github.jpg">
                                    <h2>GitHub</h2>
                                </div>
                                <hr>
                                <div class="card-body">
                                    <p>
                                  My GitHub that holds all my main repos.
                                    </p>
                       <a href="https://github.com/m-pad-studios" target="_blank">   <button type="button" class="btn btn-outline-secondary"  > Go.
                            </button></a>
                           
                                </div>
                            </div>
                            <br>
                    </div>
                    <div class="col-md-4">
                            <div class="card">
                                <div class="card-head">
                                    <img alt="Vue logo" class="rounded-circle img-custome" src="https://i.pinimg.com/originals/4a/70/56/4a70563234301578c158dc142384a1c3.png">
                                    <h2>Current Web Project</h2>
                                </div>
                                <hr>
                                <div class="card-body">
                                    <p>
                                       Finishing up Mustacheo Inds. and then onto a full Vue js web app!
                                    </p>
                                 <a href="https://mustacheoinds.herokuapp.com" target="_blank">   <button type="button" class="btn btn-outline-secondary">Explore..</button> </a>
                                </div>
                            </div>
                        <br>
                    </div>  
                    <div class="col-md-4">
                        <div class="card">
                            <div class="card-head">
                                <img alt="Vue logo" class="rounded-circle img-custome" src="https://cdn.mos.cms.futurecdn.net/wH5y2PkWhCxqKBje8rBp5e.jpg">
                                <h2>Web projects</h2>
                            </div>
                            <hr>
                            <div class="card-body">
                                <p>
                                    A gallery of my personally made web apps. Each app has a section detailing how I went about building that app from start to finish. 
                                </p>
                                <button type="button" class="btn btn-outline-secondary">More!</button>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
             <button type="button" class="btn btn-primary btn-lg" v-on:click="contact">Contact</button>
        </section>
        
</template>

<script lang="ts">
export default {
    

    methods: {
       
        contact: function (event) {
                var link = "mailto:mpadinds@gmail.com";
    
            window.location.href = link;
            if(event) {
console.log(event);
            }
        }
    }
}
</script>

<style scoped>
#barz {
    border: 1px solid white;
}

.card {
    height: 500px;
}
.protfolio{
        background-color: #34345238;
        padding-top: 2%;
        padding-bottom: 15%;
        /* padding:15% */
    }
    .img-custome{
        width: 140px;
        height: 140px;
        margin-top: 15px;
    }
</style>
