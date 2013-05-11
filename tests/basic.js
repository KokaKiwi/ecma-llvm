#!/usr/bin/env node

function process(data, cb)
{
    var console;
    console.log(data);
    cb(data);
}

process(25, function() {
    var console;
    console.log("CALLBACK");
});
