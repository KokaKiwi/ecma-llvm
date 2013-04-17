// Complex script, from Javascript's Wikipedia page.

function LCMCalculator(x, y) {
    var checkInt = function (x) {
        if (x % 1 !== 0) {
            throw new TypeError(x + " is not an integer");
        }
        return x;
    };
    this.a = checkInt(x);
    this.b = checkInt(y);
}

LCMCalculator.prototype = {
    constructor: LCMCalculator,
    gcd: function () {
        var a = Math.abs(this.a), b = Math.abs(this.b), t;
        if (a < b) {
            t = b;
            b = a;
            a = t;
        }
        while (b !== 0) {
            t = b;
            b = a % b;
            a = t;
        }
        this['gcd'] = function () {
            return a;
        };
        return a;
    },
    "lcm" : function () {
        var lcm = this.a / this.gcd() * this.b;
        this.lcm = function () {
            return lcm;
        };
        return lcm;
    },
    toString: function () {
        return "LCMCalculator: a = " + this.a + ", b = " + this.b;
    }
};

function output(x) {
    document.body.appendChild(document.createTextNode(x));
    document.body.appendChild(document.createElement('br'));
}

[[25, 55], [21, 56], [22, 58], [28, 56]].map(function (pair) {
    return new LCMCalculator(pair[0], pair[1]);
}).sort(function (a, b) {
    return a.lcm() - b.lcm();
}).forEach(function (obj) {
    output(obj + ", gcd = " + obj.gcd() + ", lcm = " + obj.lcm());
});