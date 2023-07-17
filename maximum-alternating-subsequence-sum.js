/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAlternatingSum = function (nums) {
    var dp0, dp1, dp_prev0 = nums[0], dp_prev1 = 0;
    for (var i = 0; i < nums.length; ++i) {
        dp0 = max(dp_prev0, dp_prev1 + nums[i]);
        dp1 = max(dp_prev1, dp_prev0 - nums[i]);
        dp_prev0 = dp0;
        dp_prev1 = dp1;
    }
    return dp0;
};

function max(num1, num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

console.log(maxAlternatingSum([4, 2, 5, 3]));