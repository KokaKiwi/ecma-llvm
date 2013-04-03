
var Class = function()
{
    this.lol = 20;
};

Class.prototype = {
    print: function() {
        return this.lol;
    }
};

function createClass()
{
    return new Class(20);
}

var instance = createClass();
