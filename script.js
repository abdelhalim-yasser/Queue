let menuOpen = false;

function toggleMenu() {
    const nav = document.getElementById("nav");
    const icon = document.getElementById("menu-icon");
    menuOpen = !menuOpen;

    if (menuOpen) {
        nav.classList.add("open");
        icon.classList.replace("fa-bars", "fa-times");
    } else {
        nav.classList.remove("open");
        icon.classList.replace("fa-times", "fa-bars");
    }
}

window.addEventListener("resize", () => {
    if (window.innerWidth >= 768) {
        document.getElementById("nav").classList.remove("open");
        document
            .getElementById("menu-icon")
            .classList.replace("fa-times", "fa-bars");
        menuOpen = false;
    }
});


// Queue Implementation
let queue = [];

function renderQueue() {
    const container = document.getElementById("queue-container");
    container.innerHTML = "";
    queue.forEach((item) => {
        const div = document.createElement("div");
        div.className = "queue-item";
        div.innerText = item;
        container.appendChild(div);
    });
    updateStats();
}

function updateStats() {
    const front = queue[0];
    const rear = queue[queue.length - 1];
    const sum = queue.reduce((a, b) => a + b, 0);
    const avg = queue.length ? (sum / queue.length).toFixed(2) : "-";
    const max = queue.length ? Math.max(...queue) : "-";
    const min = queue.length ? Math.min(...queue) : "-";

    document.getElementById("front").innerText = queue.length ? front : "-";
    document.getElementById("rear").innerText = queue.length ? rear : "-";
    document.getElementById("count").innerText = queue.length;
    document.getElementById("sum").innerText = queue.length ? sum : "-";
    document.getElementById("avg").innerText = avg;
    document.getElementById("max").innerText = max;
    document.getElementById("min").innerText = min;
}

function enqueue() {
    const input = document.getElementById("queue-input");
    const value = parseInt(input.value);

    if (isNaN(value))
        return;

    queue.push(value);
    input.value = "";
    renderQueue();
}

function dequeue() {
    if (queue.length === 0)
        return alert("Queue is empty!");

    queue.shift();
    renderQueue();
}

function peekFront() {
    if (queue.length === 0)
        return alert("Queue is empty!");

    alert("Front: " + queue[0]);
}

function printQueue() {
    if (queue.length === 0)
        return alert("Queue is empty!");

    alert("Queue: " + queue.join(" → "));
}

function openSearchMenu() {
    let choice = prompt(
        `Choose an option:
1 - isFound(value)
2 - getIndex(value)
3 - getElement(index)
4 - getMiddle()
5 - getLast()`
    );

    switch (choice) {
        case "1":
            isFound(parseInt(prompt("Enter value:")));
            break;
        case "2":
            getIndex(parseInt(prompt("Enter value:")));
            break;
        case "3":
            getElement(parseInt(prompt("Enter index:")));
            break;
        case "4":
            getMiddle();
            break;
        case "5":
            getLast();
            break;
        default:
            alert("Invalid choice");
    }
}

function swapValues() {
    const a = Number(prompt("Enter first value to swap:"));
    const b = Number(prompt("Enter second value to swap:"));

    const i = queue.indexOf(a);
    const j = queue.indexOf(b);

    if (i === -1 || j === -1) return alert("One or both values not found.");
    [queue[i], queue[j]] = [queue[j], queue[i]];

    renderQueue();
}

function swapIndex() {
    const i1 = parseInt(prompt("Enter first index:"));
    const i2 = parseInt(prompt("Enter second index:"));

    if (i1 < 0 || i1 >= queue.length || i2 < 0 || i2 >= queue.length)
        return alert("Invalid indices");

    [queue[i1], queue[i2]] = [queue[i2], queue[i1]];
    renderQueue();
}

function removeDuplicates() {
    queue = [...new Set(queue)];
    renderQueue();
}

function reverseQueue() {
    queue.reverse();
    renderQueue();
}

function randomize() {
    if (queue.length === 0)
        return alert("Queue is empty!");

    for (let i = queue.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [queue[i], queue[j]] = [queue[j], queue[i]];
    }

    renderQueue();
}

function sortQueue() {
    queue.sort((a, b) => a - b);
    renderQueue();
}

function clearQueue() {
    queue = [];
    renderQueue();
}

function isFound(value) {
    alert(queue.includes(value) ? "Value exists" : "Value not found");
}

function getIndex(value) {
    const idx = queue.indexOf(value);
    alert(idx !== -1 ? "Index: " + idx : "Value not found");
}

function getElement(index) {
    alert(
        queue[index] !== undefined ? "Element: " + queue[index] : "Invalid index"
    );
}

function getMiddle() {
    if (queue.length === 0)
        return alert("Queue is empty");

    const mid = Math.floor(queue.length / 2);
    alert("Middle element: " + queue[mid]);
}

function getLast() {
    if (queue.length === 0)
        return alert("Queue is empty");

    alert("Last element: " + queue[queue.length - 1]);
}

function openHelp() {
    document.getElementById("helpOverlay").style.display = "block";
}

function closeHelp() {
    document.getElementById("helpOverlay").style.display = "none";
}

window.addEventListener("load", () => {
    openHelp();
    renderQueue();
});
