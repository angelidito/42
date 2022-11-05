let title = React.createElement('h1', {style: { backgroundColor: '#30af99' } }, 'Hola 42')

// Con JSX
function App() {
	return (
		<div style={{ backgroundColor: "#3af"}}>
			<h1>Hola mundo</h1>
			{console.log("ahfkl")}
			<h2>¿Cómo estás?</h2>
		</div>
	);
}

let rootNode = document.getElementById("root");

// console.log(rootNode);

let root = ReactDOM.createRoot(rootNode);
// root.render(title);
root.render(React.createElement(App));