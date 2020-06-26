# std::string

## 문자 추가하기

`push_back` 과 `+=` 연산자가 동일한 기능을 수행한다.

```c++
string s;
s.push_back('a');
s += 'a';
```

## 문자열 추가하기

`append` 와 `+=` 연산자가 동일한 기능을 수행한다.
    
```c++
string s;
s.append("abc");
s += "abc";
``````

## 인덱스로 문자에 접근하기

`at`과 `[]`이 동일한 기능을 수행한다.

```c++
string s = "abc"
int i = 1;
char c1 = b.at(i);
char c2 = b[i];
```

## 문자열 비교하기

연산자 오버로딩을 통해 `==` 연산자가 `compare` 와 같이 동작한다. 문자형 포인터(`char *`)를 이용한 문자열의 경우 변수는 주소를 가리키므로 `==` 연산자 대신 `strcmp` 함수를 사용한다.

```c++
string s1 = "abcd";
string s2 = "abcd";
if (c == d) {
    cout << c << " is the same as " << d << endl;
}
// 값이 0보다 작은 경우, s1이 s2보다 사전적으로 앞에 위치
// 값이 0인 경우, 두 문자열이 동일
// 값이 0보다 큰 경우, s1이 s2보다 사전적으로 뒤에 위치
if (c.compare(d) == 0) {
    cout << c << " is the same as " << d << endl;
}
```

```c++
int strcmp(const char *s1, const char *s2) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0')
            return 0;
    }
    return s1[i] - s2[i];
}
```

## 문자열 복사하기

`=` 연산자를 사용하면 `assign` 함수를 이용한 복사와 동일하게 동작한다.

```c++
void strcpy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}
```

## 문자형 포인터로 변환하기

`string` 을 인식하지 못하는 이전 함수들을 호출할 때는 `data`, `c_str` 함수를 통해 문자 배열이나 문자형 포인터로의 변환이 필요하다.

두 함수 모두 상수 포인터(`const char *`)를 리턴한다. ~~두 함수에는 차이점이 존재하는데 `data` 함수는 `string` 객체의 데이터 번지를 그대로 리턴하므로 널 문자로 종료되지 않을 수도 있는 반면에 `c_str` 함수는 항상 널 문자를 포함한다.~~  
C++11 이후로 두 함수는 동일하게 동작한다.

```c++
string s = "abc";
s.data(); 
s.c_str();
```
