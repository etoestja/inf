stock_prices_yesterday = [10, 7, 5, 8, 11, 9]

#find: max(x[j]-x[i]) i < j

r=None

for i in xrange(len(stock_prices_yesterday)):
  for j in xrange(len(stock_prices_yesterday)):
    if i < j:
      if r == None or stock_prices_yesterday[j] - stock_prices_yesterday[i] > r[2]:
        r = (i, j, stock_prices_yesterday[j] - stock_prices_yesterday[i])
print stock_prices_yesterday
print r
