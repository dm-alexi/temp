function setCookie(value)
{
    var list = document.getElementById("ft_list");
    var expire = new Date();
    expire.setMonth(expire.getMonth() + 1);
    document.cookie = "name=" + value + ";expires=" + expire.toGMTString();
    alert("content=" + value + ";expires=" + expire.toGMTString());
    alert(document.cookie);
}

function savelist() 
{
    var listObject = {};
    var str = '';
    var list = document.getElementById("ft_list");
    for (var count = 0; count < list.children.length; count++) {
        listObject.pos = count;
        listObject.val = list.children[count].textContent;
        str += JSON.stringify(listObject);
    }
    setCookie(str);
}

function delEntry()
{
    var list = document.getElementById("ft_list");
    if (confirm("Are you sure you want to delete: \"" + this.textContent.substr(2) + "\"?"))
        this.remove();
    savelist();
}

function addEntry()
{
    var entry = prompt("What should be done?");
    if (entry != null && entry != "")
    {
        var list = document.getElementById("ft_list");
        var elem = document.createElement("div");
        elem.onclick = delEntry;
        elem.appendChild(document.createTextNode("- " + entry));
        list.prepend(elem);
        savelist();
    }
}

var list = document.getElementById("ft_list");
//console.log(list.cookie);
alert(document.cookie);