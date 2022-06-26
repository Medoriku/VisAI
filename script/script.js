const btn = document.querySelector('.plant__condition_button');
const det = document.querySelector('.plant__detected');

console.log(det);

btn.addEventListener('click', () => {
    det.style.display = "block";
})