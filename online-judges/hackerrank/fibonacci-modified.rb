##########
# * Author: Ulises Mendez Martinez
# * Mail: ulisesmdzmtz@gmail.com
# * Solution: DP to calculate fibonacci
##########
a, b, n = gets.strip.split(/\s+/).map(&:to_i)

fib = [a,b]

for i in 2...n
   fib[i] = fib[i-1] * fib[i-1] + fib[i-2]
end

puts fib[n-1]
