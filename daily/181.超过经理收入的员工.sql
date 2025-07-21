--
-- @lc app=leetcode.cn id=181 lang=mysql
--
-- [181] 超过经理收入的员工
--

-- @lc code=start
# Write your MySQL query statement below
select a.name as 'Employee'
from Employee as a, Employee as b
where a.managerId = b.id and a.salary > b.salary
-- @lc code=end

