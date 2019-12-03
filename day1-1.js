var sum = 0;

var modules = [103910, 133712, 82560, 91679, 98354, 89007, 93288, 132363, 91373, 83666, 55958, 90387, 100869, 98127, 120197, 86931, 60370, 143999, 71541, 115662, 51287, 81624, 58307, 60408, 141664, 89781, 127772, 132353, 101220, 104001, 140488, 58072, 75764, 120003, 82386, 77603, 130604, 86672, 120987, 80334, 67674, 52918, 98041, 102541, 97612, 50436, 129998, 84854, 101867, 82039, 108966, 80708, 54588, 86854, 89607, 71869, 126093, 89460, 86558, 77651, 53295, 132188, 137266, 97370, 114620, 86691, 147199, 147299, 72616, 142654, 88610, 104030, 64256, 54867, 76532, 145081, 102335, 72987, 72684, 148155, 59739, 85954, 141001, 125171, 107764, 141622, 89536, 92435, 69038, 84518, 119700, 119801, 81677, 125317, 72683, 128905, 93666, 75633, 117361, 82295];


var fuels = modules.map((module) => { return Math.floor(module / 3) - 2; })
var hFuel = 0;
fuels.forEach((fuel) => { hFuel += Math.sqrt(fuel); });

hFuel /= 8;

var hModule = 0;
modules.forEach((module) => { hModule += Math.sqrt(module); });

hModule /= 5;

var currentOffset = 0;

var svg = d3.select("body").append("svg")
    .attr("width", 1600)
    .attr("height", 800);


svg.append("text").attr("x", "500").attr("y", "800").attr("font-family", "sans-serif")
    .attr("font-size", "20px")
    .attr("fill", "red");
var offsetH = 0;
var offsetH2 = 0;
var offsetX = 50;
var offsetX2 = 1550;
var colors = ['rgba(179, 0, 12, 1)', 'rgba(255, 0, 18, 1)', 'rgba(216, 216, 216, 1)', 'rgba(0, 255, 62, 1)', 'rgba(0, 179, 44, 1)'];


modules = modules.map((module, i) => {
    var h = (Math.sqrt(modules[i]) / hModule) * 600;
    var h2 = (Math.sqrt(fuels[i]) / hModule) * 600;
    if (offsetH + h >= 600) { offsetX += 100; offsetH = 0; }
    if (offsetH2 + h2 >= 600) { offsetX2 -= 100; offsetH2 = 0; }

    var res = {};
    res.height = h;
    res.width = h;
    res.x = offsetX - h / 2;
    res.y = offsetH;
    res.x2 = offsetX2 - h2 / 2;
    res.y2 = offsetH2
    res.h2 = h2;
    res.value = module;
    res.value2 = fuels[i];
    res.delay = Math.floor(Math.random() * 3000 + 500);
    res.idx = i;
    offsetH += h;
    offsetH2 += h2;
    return res;
});


svg.selectAll(".module").data(modules).enter()
    .append("rect")
    .attr("class", "module")
    .attr("width", (data) => {
        return data.width;
    })
    .attr("height", (data) => {
        return data.height;
    })
    .attr('fill', (data, i) => { return colors[i % 5]; })
    .attr("x", -Math.random() * 1000)
    .attr("y", -Math.random() * 1000)
    .transition().duration((data, i) => { return data.delay; })
    .attr("x", (data) => {
        return data.x;
    })
    .attr("y", (data) => {
        return data.y;
    }).transition().delay((data, i) => { return 3500 - data.delay + data.idx * 300; }).duration(300)
    .attr("x", (data) => {
        return 1000;
    }).attr("y", (data) => {
        return 0;
    }).transition().delay((data, i) => { return 300; }).duration(300)
    .attr("width", (data) => {
        return data.h2;
    }).attr("height", (data) => {
        return data.h2;
    }).transition().delay((data, i) => { return 300; }).duration(300)
    .attr("x", (data) => {

        return data.x2;
    }).attr("y", (data) => {
        return data.y2;
    }).on("end", (element) => {
        sum += element.value2;
        svg.select("text").text(sum);
    });

/*

var currentIdx = 0;

offsetX = 1550;
offsetH = 0;

d3.selectAll(".module").transition().delay((_, i) => {
    i * 2000 + 3000
}).duration(1000).attr("x")

var int = setInterval(treatVolume, 5000);
function treatVolume() {
    if (currentIdx >= allElements.length) {
        int();
        return;
    }
    var element = allElements[currentIdx];

    var fuel = fuels[currentIdx];

    var h = (Math.sqrt(fuel) / hFuel) * 800;
    if (offsetH + h >= 800) { offsetX -= 100; offsetH = 0; }

    d3.select(element).transition().duration(1000).attr("x", offsetX - h / 2).attr("y", offsetH);
    offsetH += h;
    currentIdx += 1;
}






*/



