function setCookie(value)
{
    var expire = new Date();
    expire.setMonth(expire.getMonth() + 1);
    document.cookie = "name=" + value + ";expires=" + expire.toGMTString();
}

function getCookie(cookie_name) 
{
    var res = document.cookie.match('(^|;) ?' + cookie_name + '=([^;]*)(;|$)');
    if (res)
        return (unescape(res[2]));
    else
        return null;
}

function savelist() 
{
    var arr = [];
    var list = document.getElementById("ft_list");
    for (var i = 0; i < list.children.length; ++i)
        arr[i] = list.children[i].textContent;
    setCookie(JSON.stringify(arr));
}

function delEntry()
{
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
window.onload = function()
{
    var list = document.getElementById("ft_list");
    var lst = JSON.parse(getCookie("name"));
    for (var i = 0; i < lst.length; ++i)
    {
        var elem = document.createElement("div");
        elem.onclick = delEntry;
        elem.appendChild(document.createTextNode(lst[i]));
        list.append(elem);
    }
}