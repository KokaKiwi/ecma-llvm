#!/usr/bin/env node

var print = extern Ecma_print;

var console = {
    log: function(msg)
    {
        print(msg + "\n");
    },
    fn: function(data, cb)
    {
        var i = 0;
        while (i < data.length)
        {
            cb(data[i]);
        }
    }
};

console.fn([1, 2, 3], function(item) {
    console.log(item);
});
