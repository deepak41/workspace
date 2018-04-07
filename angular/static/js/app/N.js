if (!window.N) {
    window.N = {};
};

N.notify = function(message, type) {
    $.notify(message, type);
};

N.util = {
    toTitleCase : function(str) {
        return str.replace(/\w\S*/g, function(txt){return txt.charAt(0).toUpperCase() + txt.substr(1).toLowerCase();});
    }
};
