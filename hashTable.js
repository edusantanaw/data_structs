const hashs = {};

const hashOperator = (val) => {
  let rest = val % 100;
  let restValue = val - rest;
  return { rest, restValue };
};

const numbers = [
  100000, 209321, 2312324, 84832, 4852, 4832, 2013012, 34012, 341412, 34142355,
  34143355, 65462324,
];

const allocIndex = (index, val) => {
  if (hashs[index]) {
    allocIndex(index + 1, val);
  } else {
    hashs[index] = val;
  }
};

function getByIndex(index, val) {
  const indexVal = hashs[index] + index;
  if (!indexVal) return false;
  if (indexVal != index + val) {
    return getByIndex(index + 1, val);
  } else {
    return true;
  }
}

numbers.forEach((e) => {
  const { rest, restValue } = hashOperator(e);
  allocIndex(rest, restValue);
});

function getByHashTables(val) {
  const { rest, restValue } = hashOperator(val);
  const value = getByIndex(rest, restValue);
  return value;
}

console.log(getByHashTables(4832132152));
