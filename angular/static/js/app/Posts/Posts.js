'use strict';

angular.module('Posts', ['ngRoute', 'ngResource', 'angularSpinner'])

.config(['$routeProvider', function($routeProvider) {
    $routeProvider.when('/posts', {
        templateUrl: '/static/ui/posts.html?v=' + N.appSettings.ver,
        controller: 'PostsCtrl'
    });
}])

.factory('Posts', ['$resource', function($resource) {
    return $resource('/api/posts', {}, {
      get: {method:'GET', isArray:true},
      delete: {method:'DELETE', isArray:false}
    });
}])

.controller('PostsCtrl', function($scope, $routeParams, Posts, $http, $location, $route) {
    $scope.errorMessage = false;
    $scope.page = 1;

    var loadData = function() {
        $scope.busy = true;
        $scope.posts = Posts.get({page:$scope.page}, function() {
            $scope.busy = false;
        }, function(response) {
            $scope.busy = false;
            if (angular.isObject(response.data) && response.data.message) {
                $scope.errorMessage = response.data.message;
            } else {
                $scope.errorMessage = response.data;
            }
        });
    };

    $scope.prevPage = function() {
        if ($scope.page > 1) {
            $scope.page--;
            loadData();
        }
    };

    $scope.nextPage = function() {
        $scope.page++;
        loadData();
    };

    $scope.remove = function(e, post) {
    	if (!confirm("Are you sure?")) {
    		return;
    	}
        var withId = _.find($scope.posts, function(s) {
            return post._id === s._id;
        });


        Posts.delete({_id:post._id}, function() {
            var index = $scope.posts.indexOf(withId);
            if (index > -1) $scope.posts.splice(index, 1);
        },
        function(response){
        	var message = "There was an error saving."
    		if (angular.isObject(response.data) && response.data.message) {
                message = response.data.message;
            }
    		N.notify(message, "error");
        });
    };

    loadData();
});