var module = angular.module("sampleApp", ['ngRoute']);

module.config(['$routeProvider',
    function ($routeProvider) {
        $routeProvider.
                when('/users', {
                    templateUrl: 'partials/users.html',
                    
                }).
                when('/items', {
                    templateUrl: 'templates/page2.html',
                    controller: 'Route2Controller'
                }).
                when('/orders', {
                    templateUrl: 'templates/mypage.html'

                }).
                otherwise({
                    redirectTo: '/users'
                });
    }]);