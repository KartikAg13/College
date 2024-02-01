const title = document.querySelector("#main-heading");
title.style.color = "red";
console.log(title.getAttribute("class"));

const listItems = document.querySelectorAll(".list-items");
for(i = 0; i < listItems.length; i++)
    listItems[i].style.fontSize = "2rem";

const ul = document.querySelector("ul");
const li = document.createElement("li");
ul.append(li);

li.innerText = "X-Men";
li.setAttribute("id", "main-heading");
console.log(li.getAttribute("id"));
li.removeAttribute("id");

console.log(li.getAttribute("class"));
li.classList.add("list-items");
console.log(li.getAttribute("class"));

li.remove();

console.log(ul.parentNode);
console.log(ul.parentElement.parentElement);
console.log(ul.childNodes);
ul.childNodes[3].style.backgroundColor = "blue";
console.log(ul.firstChild);
console.log(ul.lastElementChild);
console.log(ul.previousSibling);
console.log(ul.nextElementSibling);