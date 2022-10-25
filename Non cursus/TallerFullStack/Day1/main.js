import { Coche, Comida as Pizza } from "./Dest.mjs"

console.log("Hola mundo");

/**
 * Variables
 * 	Text, Number, Boolean, function, Object
 * var: global vars
 * let: local
 * const: constant
 * 
 * Functions:
 * 		Explicit
 * 		Implicit
 */

function sum(a, b) {
	return (a + b);
}
console.log(sum);

console.log(sum(1, 4));

const S = function sum(a, b) {
	return (a + b);
};

console.log("Suma: " + S(54, 123));

const R = (a, b) => {
	return (a - b);
};

console.log("Resta: " + R(54, 123));

// * Objetos:
let Person = {
	name: "Mori",
	age: 25,
	friends: ["Irene", "Sarita", "Joaquín"],
	Pet: {
		name: "Pollo",
		species: "Cat",
	},
	// run: function run(km) {
	// 	console.log(`${this.name} ha corrido ${km} kilometros...`)
	// },
	// correr: (km) => {
	// 	console.log(`${this.name} ha corrido ${km} kilometros... pero no puedes usar this, por eso no sale el nombre`)
	// },
};

console.log(Person);
console.log(Person.name + ", " + Person.age);
console.log(Person['name'] + ", " + Person["age"]);
console.log(`My person is ${Person.name} & he is ${Person.age} years old.`);


let clave = "friends";
console.log(Person.Pet.name + Person.Pet.species);
console.log("Friends: " + Person[clave]);
console.log("Friend 2: " + Person[clave][1]);

// Person.run(234);
// Person.correr(234);


let arr1 = [1, 2, 3, 4, 5];

function multSqrPrint(num, idx, arr) {
	console.log(arr);
	console.log(`Index ${idx} = ${num}`);
	return (2 * num);
}

let arr2 = arr1.map(multSqrPrint);

console.log(arr2);

let arr3 = arr1.map((num, idx) => {
	return (`Index ${idx} = ${num}`)
});

let { name, age } = Person;

console.log(name);
console.log(age);

let Escuela = {
	name: 42,
	directoin: "sldkfjs;kdf",
	antiguedad: 20,
};

let Salon = {
	alumnos: 20,
	profe: "javier",
	...Escuela,
};


console.log(Coche);
console.log(Pizza);

const calentarHorno = () => {
	setTimeout(() => {
		console.log("Calentar pizza");
	}, 3000);
}

async function DiaNormal() {
	await calentarHorno();
	console.log("limpiar");
	console.log("ver tele");
}

DiaNormal();