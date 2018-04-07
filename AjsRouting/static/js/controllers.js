module.controller("Route1Controller", function ($scope) {
    $scope.cars = ['AUDI', 'BMW', 'MERCEDES'];
    $scope.my = { favorite: 'AUDI' };    

});
module.controller("Route2Controller", function ($scope) {
    $scope.clickCounter = 0;
    $scope.check = function () {
        $scope.clickCounter++;
    };
});

