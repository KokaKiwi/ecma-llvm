
var validate = function(data) {
    return data == 2;
};

callee(10, validate);
callee(20, function(d) {
    return false;
});

var named = function lol() {
    return false;
};

var empty = function() {};

(function() {

})();
