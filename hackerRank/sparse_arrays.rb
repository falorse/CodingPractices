def matching_strings(strings, queries)
  result = []
  for i in 0..queries.size - 1
    count = 0
    for j in 0..strings.size - 1
      if strings[j] == queries[i]
        count = count + 1
      end
    end
    result[i] = count
  end

  return result
end

strings = ['ab','aba','aba']
queries = ['ab','aba','bc']

result = matching_strings(strings, queries)

puts result.join(' ')
