window.onload = () => {

    const input = document.querySelector(".input_text");
    const button = document.querySelector(".btn");
    const output = document.querySelector(".output");

    button.addEventListener('click', (event) => {
        fetch('/api/v0', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ 'line': input.value })
        }).then((resp) => {
            return resp.text();
        }).then((result) => {
            output.innerHTML = result.trim().replace(/\^(\d+(\.\d+)?)/g, "<sup>$1</sup>").replace(/\n/g, '<br>');
            output.classList.remove("hidden");
        });
    });
};