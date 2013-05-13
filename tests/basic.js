#!/usr/bin/env node

var stdio = null;

function print(data)
{
    stdio.write(data);
}

var console = {
    log: function(msg)
    {
        print(msg + "\n");
    }
};

function process(data, cb)
{
    console.log(data);
    if (cb)
    {
        cb(data);
        return true;
    }
    return false;
}

process("Hello", function(data) {
    console.log("Callback: " + data);
});

stdio[10] = 20;
