var numberOfSquares = 6;
var colors = [];
var pickedColor;
var modebtn = document.querySelectorAll(".mode");
var squares = document.querySelectorAll(".square");
var colorDisplay = document.getElementById("colorDisplay");
var messageDisplay = document.querySelector('#message');
var h1 = document.querySelector('h1');
var resetButton = document.querySelector('#reset');

init();

function init() {
    setupModeBtn();
    setupSquares();
    reset();
}

function setupModeBtn() {
    for (var i = 0; i < modebtn.length; i++) {
        // mode buttons event listener
        modebtn[i].addEventListener("click", function() {
            modebtn[0].classList.remove("selected");
            modebtn[1].classList.remove("selected");
            this.classList.add("selected");
            this.textContent === "Easy" ? numberOfSquares = 3 : numberOfSquares = 6;
            // if (this.textContent = "Easy") {
            //     numberOfSquares = 3;
            // } else {
            //     numberOfSquares = 6;
            // }
            reset();
        });
    }
}

function setupSquares() {
    for (var i = 0; i < squares.length; i++) {
        // add click listeners to squares
        squares[i].addEventListener("click", function() {
            // grab color of clicked square
            var clickedColor = this.style.backgroundColor;
            // compare color to clicked color
            if (clickedColor === pickedColor) {
                messageDisplay.textContent = 'Correct!';
                resetButton.textContent = 'Playagain?';
                changeColor(clickedColor);
                h1.style.backgroundColor = clickedColor;
            } else {
                this.style.backgroundColor = '#232323';
                messageDisplay.textContent = 'TryAgain';
            }
        });
    }
}

function reset() {
    colors = generateRandomColors(numberOfSquares);
    pickedColor = pickColor();
    colorDisplay.textContent = pickedColor;
    resetButton.textContent = "New Colors";
    messageDisplay.textContent = "";
    for (var i = 0; i < squares.length; i++) {
        if (colors[i]) {
            squares[i].style.display = "block";
            squares[i].style.backgroundColor = colors[i];
        } else {
            squares[i].style.display = "none";
        }
    }
    h1.style.backgroundColor = "steelblue";
}


// easybtn.addEventListener("click", function() {
//     hardbtn.classList.remove("selected");
//     easybtn.classList.add("selected");
//     numberOfSquares = 3;
//     colors = generateRandomColors(numberOfSquares);
//     pickedColor = pickColor();
//     colorDisplay.textContent = pickedColor;
//     for (var i = 0; i < squares.length; i++) {
//         if (colors[i]) {
//             squares[i].style.backgroundColor = (colors[i]);
//         } else {
//             squares[i].style.display = "none";
//         }
//     }
// });

// hardbtn.addEventListener("click", function() {
//     easybtn.classList.remove("selected");
//     hardbtn.classList.add("selected");
//     numberOfSquares = 6;
//     colors = generateRandomColors(numberOfSquares);
//     pickedColor = pickColor();
//     colorDisplay.textContent = pickedColor;
//     for (var i = 0; i < squares.length; i++) {
//         squares[i].style.backgroundColor = (colors[i]);
//         squares[i].style.display = "block";
//     }
// });

resetButton.addEventListener("click", function() {
    reset();
    // // generate all new colors
    // colors = generateRandomColors(numberOfSquares);
    // // pick a new random color from colors 
    // pickedColor = pickColor();
    // // change colorDisplay to pickedColor
    // // change colors of squarescolorDisplay.textContent = pickedColor;
    // colorDisplay.textContent = pickedColor;

    // for (var i = 0; i < squares.length; i++) {
    //     // add initial colors to squares
    //     squares[i].style.backgroundColor = colors[i];
    // }
    // h1.style.backgroundColor = 'steelblue';
    // this.textContent = 'New Colors';
    // messageDisplay.textContent = '';
});

// console.log("hi " + pickedColor);
colorDisplay.textContent = pickedColor;


function changeColor(color) {
    // loop through all the squares.
    for (var i = 0; i < squares.length; i++) {
        // change each color to match given color
        squares[i].style.backgroundColor = color;
    }
}

function pickColor() {
    // console.log(colors.length);
    console.log(colors);
    var random = Math.floor(Math.random() * numberOfSquares);
    // console.log(random)
    return colors[random];
}

function generateRandomColors(num) {
    // make an array
    var col = [];
    // add number of random colors to an array
    for (var i = 0; i < num; i++) {
        col.push(`rgb(${Math.floor(Math.random() * 256)}, ${Math.floor(Math.random() * 256)}, ${Math.floor(Math.random() * 256)})`);
    }
    // return that array 
    return col;
}