const height = document.getElementById('height');
const weight = document.getElementById('weight');
const button = document.getElementById('button');
const app = document.getElementById('app');

let BmiValuedocument = document.createElement('h2');
BmiValuedocument.classList.add('output')
let clearButton = document.createElement('button');
clearButton.classList.add('button')
clearButton.innerText = 'Clear'

clearButton.addEventListener('click',()=>{
    app.removeChild(BmiValuedocument)
})


button.addEventListener('click',()=>{
    let heightValue  = parseInt(height.value);
    let weightValue = parseInt(weight.value);
    let BMI = weightValue/(heightValue/100)**2;
  
    app.appendChild(clearButton)
   
    if( isNaN(BMI)){
        BmiValuedocument.innerText = 'Invalid: You Must add both your height and weight!';
        app.appendChild(BmiValuedocument);
    }
    else if (BMI <= 18.5){
        BmiValuedocument.innerHTML = 'Your <span style="color:blue"> BMI </span> value  is : ' + ` <span style="color:blue">${BMI.toFixed(1)}</span>` + ' .Your BMI value falls within the <i style="color:red">underweight range</i>.';
        app.appendChild(BmiValuedocument);
    }

    else if (BMI <= 24.9){
        BmiValuedocument.innerHTML = 'Your <span style="color:blue"> BMI </span> value  is : ' + ` <span style="color:blue">${BMI.toFixed(1)}</span>` + ' .Your BMI value falls within the <i style="color:green"> Healthy range</i>.';
        app.appendChild(BmiValuedocument);
    }

    else if (BMI <= 29.9){
        BmiValuedocument.innerHTML = 'Your <span style="color:blue"> BMI </span> value  is : ' + ` <span style="color:blue">${BMI.toFixed(1)}</span>` + ' .Your BMI value falls within the <i style="color:orange">overweight range</i>.';
        app.appendChild(BmiValuedocument);
    }
    
    else{
        BmiValuedocument.innerHTML = 'Your <span style="color:blue"> BMI </span> value  is : ' + ` <span style="color:blue">${BMI.toFixed(1)}</span>` + ' .Your BMI value falls within the <i style="color:red">obese range</i>.';
        app.appendChild(BmiValuedocument);
    }   

});


