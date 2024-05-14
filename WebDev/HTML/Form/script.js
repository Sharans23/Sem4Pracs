username=document.querySelector('#name')
dob=document.querySelector('#dob')
address=document.querySelector('#address')
email=document.querySelector('#email')
contact=document.querySelector('#contact')
password=document.querySelector('#password')
form=document.querySelector('.form')
msg=document.querySelector('.msg')

form.addEventListener('submit',onsubmit)

function onsubmit(e){
    e.preventDefault();
    if(contact.value.length!=10){
        alert('Contact number is not of 10 digits')
    }
    if(username.value.length<3){
        alert('Username cannot be less than 3 digits')
    }
    console.log('submitted')
    username.value=''
    dob.value=''
    email.value=''
    address.value=''
    contact.value=''
    password.value=''

    msg.innerHTML='submitted'
}