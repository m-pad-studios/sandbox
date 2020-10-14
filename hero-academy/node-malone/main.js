// function spacer() {
// for(var i = 0; i < 1 ; i++) {
//     console.log("~~~~~~~~~~");
//     for(var j = 0; j < 1; j++){
//    console.log();
//    console.log("~~~~~~~~~~");
//
//     }
// }
// };
//
// const fetch = require("node-fetch");
// // IIFE ex.
// (() => console.log("IN MAIN"))();
//
// // closures ex
// const hero = name => {
//     let msg = "It is I " + name;
//     return () => console.log(msg);
// }
//
// spacer();
//
// const heroGreeting = hero("Mustacheo");
// heroGreeting();
//
// // async/wait
// const heroStats = async () => {
//     const stats = await fetch(`https://api.github.com/users/m-pad-studios`);
//     const jsonStats = await
//     stats.json();
//     console.log(jsonStats);
// };
// heroStats();
//
// spacer();
//
// // scope local & global ex
//
// //global
// const globalVillain = 'global villain';
//
// const showHero = () => {
//     const localHero = '| local hero';
//     return globalVillain + localHero;
// };
//
// const secondVillain = globalVillain;
//
// console.log(showHero());
//
// // const combined = secondVillain + localHero ---- throws reference error
// // can't access localHero inside showHero() func
// spacer();
//
// // reference vs value
// let powerLvl = 9000;
// let powerLvlTwo = powerLvl;
//
// console.log(powerLvl);
// console.log(powerLvlTwo);
//
// spacer();
//
// // holds a ref to actual value in memory
// let heroArr = ['Flash','Batman'];
// let heroArrTwo = heroArr;
//
// for (const hero of heroArrTwo) {
//     console.log(hero);
// }
//
// // alter the actual value in memory
// heroArrTwo[1] = 'Mustacheo';
// for (const hero of heroArrTwo) {
//     console.log(hero);
// }
//
// spacer();
//
// // callbacks. Used to unpack JSON objects
// const fetchHeroes = callback => {
//     setTimeout(() => {
//         spacer();
//         let resp = `[{name: "Mustacheo"}, {name: "Wooby"}]`;
//         callback(resp);
//     }, 500);
// };
// const showHeroes = heroes =>
// console.log(heroes);
// fetchHeroes(showHeroes);
//
// spacer();
//
// // prototyping
// function GoodHero() {
//     this.name = "Mustacheo";
//     this.powers = "Ice";
// }
//
// GoodHero.prototype.title = "Good Guy";
// GoodHero.prototype.displayHeroDeets = function() {
//     console.log(this.name + "|" + this.title + "|" + this.powers);
// }
// let goodHero = new GoodHero();
// goodHero.displayHeroDeets();
//
// spacer();

/*
 * Find vowels, print them one char a line at a time in order,
 * Then print rest of string in order one char a line at a time.
 */
const vowels = ['a','e','i','o','u'];
const order = [];
function vowelsAndConsonants(s) {

  for (let vowel of s.toLowerCase()) {
    if(vowels.includes(vowel)){
    console.log(vowel);
}
if(!vowels.includes(vowel)){
  order.push(vowel);
}
}
for(var i = 0; i < order.length; i++) {
  console.log(order[i]);
}
}

/*
 * Declare a RegExp object variable named 're'
 * It must match a string that starts and ends with the same vowel (i.e., {a, e, i, o, u})
 */
function regexVar() {

    var re = /^([aeiou]).*\1$/;


    return re;
}
// Demo that passes.
const msg = "aeioua";
const mutated = msg.match(regexVar());
console.log(mutated);

// Demo that works but doesn't pass. @Null returned
const msgTwo = "Will  return null?";
console.log(msgTwo);

const msgThree = msgTwo;
const mutatedTwo = msgTwo.match(regexVar());
console.log(`${msgThree} >>> ${mutatedTwo}`);



/*
 * Complete the reverseString function
 * Use console.log() to print to stdout.
 */
function reverseString(s) {
  try {


      var breakUp = s.split("");
      var reverb = breakUp.reverse();
      var reverbedBack = reverb.join("");

      var snapShot = reverbedBack[0];
      var copy = parseInt(snapShot);
      if(copy === Number()){
      var reverbed = parseInt(reverbedBack);

}
    s = reverbedBack;
    } catch (e) {

        console.log(e = "s.split is not a function");



    } finally {

     console.log(s);

    }
  }



reverseString("987654321");
reverseString("abcd");

/*
 * Complete the isPositive function.
 * If 'a' is positive, return "YES".
 * If 'a' is 0, throw an Error with the message "Zero Error"
 * If 'a' is negative, throw an Error with the message "Negative Error"
 */
function isPositive(a) {
    if(a > 0){
        return "YES";
    }
    if(a === 0){
    throw new Error("Zero Error");
    }
    if(a < 0){
    throw new Error("Negative Error");
    }
}


class Rectangle {
    constructor(w, h) {
        this.w = w;
        this.h = h;
    }
}

/*
 *  Write code that adds an 'area' method to the Rectangle class' prototype
 */
Rectangle.prototype.area = function() {
    if(this.h != NaN && this.w != NaN){
  var sum = this.w * this.h;
  return sum;
    }
    if(this.w === NaN){
        return this.w * this.w;
    }
    if(this.h === NaN){
        return this.h * this.h;
    }
}
/*
 * Create a Square class that inherits from Rectangle and implement its class constructor
 */
class Square extends Rectangle {
  constructor(w=null, h=3) {
    super();
    this.w = w;
    this.h = h;

  }

}

if (JSON.stringify(Object.getOwnPropertyNames(Square.prototype)) === JSON.stringify([ 'constructor' ])) {
    const rec = new Rectangle(3, 4);
    const sqr = new Square(4);

    console.log(rec.area());
    console.log(sqr.area());
} else {
    console.log(-1);
    console.log(-1);
}
