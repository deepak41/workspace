

(function() {
    var app = angular.module('sampleapp',['infinite-scroll','ngRoute',
                                            'Posts']);

    app.config(function($routeProvider, $locationProvider, $httpProvider) {
        $httpProvider.defaults.headers.delete = {'Content-Type': 'application/json'};

        $routeProvider.
            when('/', {
                templateUrl: '/static/ui/admin.html?v=' + N.appSettings.ver,
                controller: 'IndexCtrl'
            })
            .otherwise({ redirectTo: '/' });

            // configure html5 to get links working on jsfiddle
            $locationProvider.html5Mode(true);
    });

    app.filter('fromNow', function(){
        return function(ts) {
            if (!ts) {
                return ts;
            }
            return moment.unix(ts).fromNow();
        };
    });

    app.filter('datetime', function(){
        return function(ts) {
            if (!ts) {
                return ts;
            }
            return moment.unix(ts).format("YYYY-MM-DD hh:mm a");
        };
    });

    app.controller('IndexCtrl', function($scope, $route) {});
})();