function delEntry()
{
    
    if (confirm("Are you sure you want to delete: \"" + $(this).text().substr(2) + "\"?"))
    {
        $.get('delete.php', { id: $(this).attr('id'), text: $(this).text() });
        this.remove();
    }
}

$(document).ready(function ()
{
    $('#bnew').click(function()
    {
        var entry = prompt("What should be done?");
        if (entry != null && entry != "")
        {
            $('<div>', { text: "- " + entry, click: delEntry }).prependTo('#ft_list');
            $.get('insert.php', { id: `f${(+new Date).toString(16)}`, text: "- " + entry});
        }
    });
    $.get('select.php', function(data)
    {
        if (data)
        {
            var arr = data.split("\n");
            for (var i = 0; i < arr.length; ++i)
            {
                var tmp = arr[i].split(";");
                $('<div>', { id: tmp[0], text: tmp[1], click: delEntry }).appendTo('#ft_list');
            }
        }
    });
});