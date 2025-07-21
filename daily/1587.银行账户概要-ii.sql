--
-- @lc app=leetcode.cn id=1587 lang=mysql
--
-- [1587] 银行账户概要 II
--

-- @lc code=start
# Write your MySQL query statement below
# Write your MySQL query statement below
select name, sum(T.amount) as balance
from Users as U
inner join Transactions as T
on U.account = T.account
group by U.account
having sum(T.amount) > 10000
-- @lc code=end

