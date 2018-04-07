var module = angular.module("sampleApp", ['ngRoute']);

module.config(['$routeProvider',
    function ($routeProvider) {
        $routeProvider.
                when('/route1', {
                    templateUrl: '/static/angularTemplate/page1.html',
                    controller: 'Route1Controller'
                }).
                when('/route2', {
                    templateUrl: '/static/angularTemplate/page2.html',
                    controller: 'Route2Controller'
                }).
                when('/route3', {
                    templateUrl: '/static/angularTemplate/mypage.html'

                }).
                otherwise({
                    redirectTo: '/route3'
                });
    }]);