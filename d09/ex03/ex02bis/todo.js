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
    $('#ft_list').children().each(function()
    {
        arr.push($(this).text());
    });
    setCookie(JSON.stringify(arr));
}

function delEntry()
{
    if (confirm("Are you sure you want to delete: \"" + $(this).text().substr(2) + "\"?"))
        this.remove();
    savelist();
}

$(document).ready(function ()
{
    $('#bnew').click(function()
    {
        var entry = prompt("What should be done?");
        $('<div>', { text: "- " + entry, click: delEntry }).prependTo('#ft_list');
        savelist();
    });
    
    var lst = JSON.parse(getCookie("name"));
    for (var i = 0; i < lst.length; ++i)
    {
        $('<div>', { text: lst[i], click: delEntry }).appendTo('#ft_list');
    }
});