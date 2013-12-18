
var player = {
    name: 'Jane',
    age: 21,
    haircolor: 'Red',

    stats: {
        life: 100,

        caracs: {
            strength: 10,
            intel: 20,
        },
    },
};

player.stats.life -= 20;

console.log(player.stats.caracs.intel);
