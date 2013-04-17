
var t = [10, 10, (25 + 10) * 100],
    i = t[0];

result = Math.cos(i * 2);

var Object = function()
{
    this.refCount = 1;
};

Object.prototype.retain = function()
{
    this.refCount++;
};

Object.prototype.release = function()
{
    this.refCount--;

    if (this.refCount == 0)
    {
        delete(this);
    }
};

Object.prototype.strlen = function(str)
{
    var length = 0;

    for (var c in str)
        length++;

    return length;
};

var o = new Object();

try
{
    switch(o)
    {
        case 25:
            console.log("Hello world!");
            break;
        case typeof o:
            console.log(typeof o);
            break;
    }
}
catch(e)
{
    console.log(e);
}
finally
{
    console.log("Terminated.");
}
