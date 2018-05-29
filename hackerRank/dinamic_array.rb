#!/bin/ruby

#
# Complete the dynamicArray function below.
#

def perform_query(seq_list, last_answer, query)
  type = query[0].to_i
  x = query[1].to_i
  y = query[2].to_i
  size = seq_list.size

  if type == 1
    seq_list[(x ^ last_answer) % size].push(y)
    return last_answer
  elsif type == 2
    seq = seq_list[(x ^ last_answer) % size]
    last_answer = seq[y % seq.size]
    return last_answer
  end
end

def initialize_seq_list(n)
  seq_list = [n]
 for i in 0..n - 1 do
   seq_list[i] = []
 end
 return seq_list
end

def dynamicArray(n, queries)
  seq_list = initialize_seq_list(n)
  last_answer = 0
  result = []

  queries.each do |q|
    last_answer = perform_query(seq_list, last_answer, q)
    if q[0].to_i == 2
      result.push(last_answer)
    end
  end

  return result
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')
nq = gets.rstrip.split
n = nq[0].to_i
q = nq[1].to_i

queries = Array.new(q)

q.times do |queries_row_itr|
    queries[queries_row_itr] = gets.rstrip.split(' ').map(&:to_i)
end

result = dynamicArray n, queries

fptr.write result.join "\n"
fptr.write "\n"

fptr.close()
