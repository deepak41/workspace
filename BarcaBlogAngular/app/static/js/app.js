var x1=angular.module('ionicApp', ['ngResource']);

x1.factory('Post', function($resource) {
  return $resource('/api/posts');
});

x1.controller('MainCtrl', function($scope, Post) {
  // Get all posts
	$scope.posts = Post.query()

	     // Do whatever when the request is finished
});