/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF 1<<29
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

class BigInt
{
    private:
        char *digits;
        int size;            // number of used bytes (digits)
        int capacity;        // size of digits
        int sign;            // -1, 0 or +1

    public:
        /** Creates a BigInt with initial value n and initial capacity cap **/
        BigInt( int n, int cap );

        /** Creates a BigInt with initial value n **/
        BigInt( int n );

        /** Creates a BigInt with initial value floor( d ) **/
        BigInt( long double d );

        /** Creates a BigInt with value 0 **/
        BigInt();

        /** Creates a BigInt by reading the value from a string **/
        BigInt( string s );
        void setVal(string s);

        /** Creates a BigInt by reading the value from a C string **/
        BigInt( const char s[] );

        /** Copy constructor **/
        BigInt( const BigInt &n );

        /** Assignment operators **/
        const BigInt &operator=( const BigInt &n );
        const BigInt &operator=( int n );

        /** Cleans up **/
        ~BigInt();

        /** Removes any leading zeros and adjusts the sign **/
        void normalize();

        /** Returns the sign of n: -1, 0 or 1 **/
        static int sig( int n );

        /** Returns the sign of n: -1, 0 or 1 **/
        static int sig( long double n );

        /** Returns the number of decimal digits **/
        inline int length() { return size; }

        /** Arithmetic **/
        BigInt operator++();
        BigInt operator++( int );
        BigInt operator--();
        BigInt operator--( int );
        BigInt operator-();
        BigInt operator+ ( int n    );
        BigInt operator+ ( BigInt n );
        BigInt&operator+=( int n    );
        BigInt&operator+=( BigInt n );
        BigInt operator- ( int n    );
        BigInt operator- ( BigInt n );
        BigInt&operator-=( int n    );
        BigInt&operator-=( BigInt n );
        BigInt operator* ( int n    );
        BigInt operator* ( BigInt n );
        void   operator*=( int n    );
        void   operator*=( BigInt n );
        BigInt operator/ ( int n    );
        BigInt operator/ ( BigInt n );
        void   operator/=( int n    );
        void   operator/=( BigInt n );
        int    operator% ( int n    );
        BigInt operator% ( BigInt n );
        void   operator%=( int n    );
        void   operator%=( BigInt n );
        int divide( int n );              // Divides storing quotient in *this and returning the remainder
        BigInt divide( BigInt n );        // Divides storing quotient in *this and returning the remainder
        BigInt operator* ( long double n ); // Multiplies by a double and truncates (always under-estimates!)
        void   operator*=( long double n ); // Multiplies by a double and truncates (always under-estimates!)

        /** Bitwise arithmetic **/
        BigInt operator<< ( int n    );
        void   operator<<=( int n    );
        BigInt operator>> ( int n    );   // Works differently for negative numbers
        void   operator>>=( int n    );   // Works differently for negative numbers
/*
        BigInt operator&  ( int n    );
        BigInt operator&  ( BigInt n );
        void   operator&= ( int n    );
        void   operator&= ( BigInt n );
        BigInt operator|  ( int n    );
        BigInt operator|  ( BigInt n );
        void   operator|= ( int n    );
        void   operator|= ( BigInt n );
        BigInt operator^  ( int n    );
        BigInt operator^  ( BigInt n );
        void   operator^= ( int n    );
        void   operator^= ( BigInt n );
        BigInt operator~();
*/
        /** Concatenation ;-) **/
        BigInt operator,( int n );
        BigInt operator,( BigInt n );

        /** Casting **/
        bool operator!();
        operator bool();
        //operator int();   //XXX: Don't do this!!! It takes precedence over operator+(int,BigInt)
        operator string();

        /** Comparison **/
        bool operator<( BigInt n );
        bool operator>( BigInt n );
        bool operator==( BigInt n );
        bool operator<=( BigInt n );
        bool operator>=( BigInt n );
        bool operator<( int n );
        bool operator>( int n );
        bool operator==( int n );
        bool operator<=( int n );
        bool operator>=( int n );
        int compare( BigInt n );

        /** Returns the lowest value as an integer (watch out for overflow) **/
        int toInt();

        /** Returns the value as a decimal string **/
        string toString();

        /** Outputs decimal value to stdout **/
        void print();

        /** Outputs the decimal value, with commas **/
        void printWithCommas( ostream &out );

    private:
        /** Expansion **/
        void grow();

    /** I/O Friends **/
    friend istream &operator>>( istream &in, BigInt &n );
    friend ostream &operator<<( ostream &out, BigInt n );

    /** Logarithms **/
    friend long double log2( BigInt x, long double epsilon );
    inline friend long double log( BigInt x, long double epsilon );
    inline friend long double log10( BigInt x, long double epsilon );
    inline friend long double lg( BigInt x, long double epsilon );
    inline friend long double ln( BigInt x, long double epsilon );
};

BigInt operator+( int m, BigInt &n )
{
    return n + m;
}

BigInt operator-( int m, BigInt &n )
{
    return -n + m;
}

BigInt operator*( int m, BigInt &n )
{
    return n * m;
}

BigInt operator/( int m, BigInt &n )
{
    return BigInt( m ) / n;
}

BigInt operator%( int m, BigInt &n )
{
    return BigInt( m ) % n;
}

/** Misc **/
inline bool isDigit( int c )
{
    return( c >= ( int )'0' && c <= ( int )'9' );
}

/** Input/Output **/
istream &operator>>( istream &in, BigInt &n )           // FIXME: see inside
{
    n.size = 0;
    n.sign = 1;
    int sign = 1;
    int c;
    while( ( c = in.peek() ) >= 0 &&
           ( c == ' ' || c == '\t' || c == '\r' || c == '\n' ) )
        in.get();
    if( c < 0 || ( c != ( int )'-' && !isDigit( c ) ) )
    {
        in >> c;                // XXX: force in.fail()
        return in;
    }
    if( c == ( int )'-' ) { sign = -1; in.get(); }

    // FIXME: Extremely inefficient! Use a string.
    while( ( c = in.peek() ) >= 0 && isDigit( c ) )
    {
        in.get();
        n *= 10;
        n += ( c - ( int )'0' );
    }
    n.sign = sign;      //XXX: assign n.sign directly after fixing the FIXME
    n.normalize();
    return in;
}

ostream &operator<<( ostream &out, BigInt n )       //FIXME: make more efficient
{
    return out << n.toString();
}

BigInt::BigInt( int n, int cap )
{
    cap = max( cap, ( int )sizeof( n ) * 8 );
    capacity = cap;
    sign = sig( n );
    n *= sign;
    digits = new char[cap];
    memset( digits, 0, cap );
    for( size = 0; n; size++ )
    {
        digits[size] = n % 10;
        n /= 10;
    }
}

BigInt::BigInt( int n )
{
    capacity = 1024;
    sign = sig( n );
    n *= sign;
    digits = new char[capacity];
    memset( digits, 0, capacity );
    size = 0;
    while( n )
    {
        digits[size++] = n % 10;
        n /= 10;
    }
}

BigInt::BigInt( long double d )
{
    capacity = 1024;
    sign = ( d < 0 ? -1 : d > 0 ? 1 : 0 );
    d *= sign;
    digits = new char[capacity];
    memset( digits, 0, capacity );
    size = 0;
    d = floor( d );
    while( d > 0 )
    {
       // digits[size++] = 0 >? ( int )( ( d - floor( d / 10 ) * 10 ) + 0.5 ) <? 9;
        d = floor( d / 10 );
    }
}

BigInt::BigInt()
{
    capacity = 128;
    sign = 0;
    digits = new char[capacity];
    memset( digits, 0, capacity );
    size = 0;
}

BigInt::BigInt( string s )
{
    capacity = max( ( int )s.size(), 16 );
    sign = 0;
    digits = new char[capacity];
    memset( digits, 0, capacity );

    istringstream in( s );
    in >> ( *this );
}
void BigInt::setVal( string s )
{
    capacity = max( ( int )s.size(), 16 );
    sign = 1;
    digits = new char[capacity];
    memset( digits, 0, capacity );
    size = s.size();
    for(int i = 0;i<size;i++)
        digits[i] = s[i] - '0';

  //  cout<<digits<<endl;
}
BigInt::BigInt( const char s[] )
{
    capacity = max( ( int )strlen( s ), 16 );
    sign = 0;
    digits = new char[capacity];
    memset( digits, 0, capacity );

    istringstream in( s );
    in >> ( *this );
}

BigInt::BigInt( const BigInt &n )
{
    capacity = n.capacity;
    sign = n.sign;
    size = n.size;
    digits = new char[capacity];
    memcpy( digits, n.digits, capacity );
}

const BigInt &BigInt::operator=( const BigInt &n )
{
    if( &n != this )
    {
        if( capacity < n.size )
        {
            capacity = n.capacity;
            delete [] digits;
            digits = new char[capacity];
        }
        sign = n.sign;
        size = n.size;
        memcpy( digits, n.digits, size );
        memset( digits + size, 0, capacity - size );
    }
    return *this;
}

const BigInt &BigInt::operator=( int n )
{
    sign = sig( n );
    n *= sign;
    for( size = 0; n; size++ )
    {
        digits[size] = n % 10;
        n /= 10;
    }
    return *this;
}

BigInt::~BigInt()
{
    delete [] digits;
}

void BigInt::normalize()
{
    while( size && !digits[size-1] ) size--;
    if( !size ) sign = 0;
}

int BigInt::sig( int n )
{
    return( n > 0 ? 1 : ( n == 0 ? 0 : -1 ) );
}

int BigInt::sig( long double n )
{
    return( n > 0 ? 1 : ( n == 0 ? 0 : -1 ) );
}

int BigInt::toInt()
{
    int result = 0;
    for( int i = size - 1; i >= 0; i-- )
    {
        result *= 10;
        result += digits[i];
        if( result < 0 ) return sign * 0x7FFFFFFF;
    }
    return sign * result;
}

string BigInt::toString()
{
    string s = ( sign >= 0 ? "" : "-" );
    for( int i = size - 1; i >= 0; i-- )
        s += ( digits[i] + '0' );
    if( size == 0 ) s += '0';
    return s;
}

void BigInt::print()        //FIXME: make more efficient
{
    cout << toString();
}

void BigInt::printWithCommas( ostream &out )
{
    if( sign < 0 ) out.put( '-' );
    for( int i = size - 1; i >= 0; i-- )
    {
        out.put( digits[i] + '0' );
        if( !( i % 3 ) && i ) out.put( ',' );
    }
    if( size == 0 ) out.put( '0' );
}

void BigInt::grow()
{
    char *olddigits = digits;
    int oldCap = capacity;
    capacity *= 2;
    digits = new char[capacity];
    memcpy( digits, olddigits, oldCap );
    memset( digits + oldCap, 0, oldCap );
    delete [] olddigits;
}

BigInt BigInt::operator++()
{
    operator+=( 1 );
    return *this;
}

BigInt BigInt::operator++( int )
{
    return operator++();
}

BigInt BigInt::operator--()
{
    operator-=( 1 );
    return *this;
}

BigInt BigInt::operator--( int )
{
    return operator--();
}

BigInt BigInt::operator-()
{
    BigInt result( *this );
    result.sign *= -1;
    return result;
}

BigInt BigInt::operator+( int n )
{
    BigInt result( *this );
    result += n;
    return result;
}

BigInt BigInt::operator+( BigInt n )
{
    BigInt result( *this );
    result += n;
    return result;
}

BigInt &BigInt::operator+=( int n )
{
    if( size == capacity ) grow();

    int nsign = sig( n );
    if( !nsign ) return *this;
    if( !sign ) sign = nsign;
    if( sign == nsign )
    {
        n *= nsign;
        int carry = 0;
        int i;
        for( i = 0; n || carry; i++ )
        {
            int dig = n % 10;
            int newdig = digits[i] + dig + carry;
            digits[i] = newdig % 10;
            carry = newdig / 10;
            n /= 10;
        }
        size = max( i, size );
    }
    else operator-=( -n );
    return *this;
}

BigInt &BigInt::operator+=( BigInt n )
{
    int maxS = max( size, n.size ) + 1;
    while( maxS >= capacity ) grow();        //FIXME: this is stupid

    if( !n.sign ) return *this;
    if( !sign ) sign = n.sign;
    if( sign == n.sign )
    {
        int carry = 0;
        int i;
        for( i = 0; i < maxS - 1 || carry; i++ )
        {
            int newdig = carry;
            if( i < size ) newdig += digits[i];
            if( i < n.size ) newdig += n.digits[i];
            digits[i] = newdig % 10;
            carry = newdig / 10;
        }
        size = max( i, size );
    }
    else
    {
        n.sign *= -1;
        operator-=( n );
        n.sign *= -1;
    }
    return *this;
}

BigInt BigInt::operator-( int n )
{
    BigInt result( *this );
    result -= n;
    return result;
}

BigInt BigInt::operator-( BigInt n )
{
    BigInt result( *this );
    result -= n;
    return result;
}

BigInt &BigInt::operator-=( int n )
{
    if( size == capacity ) grow();

    int nsign = sig( n );
    if( !nsign ) return *this;
    if( !sign ) sign = 1;
    if( sign == nsign )
    {
        BigInt bin = n;
        if( sign >= 0 && *this < bin || sign < 0 && *this > bin )
        {
            // Subtracting a bigger number
            operator=( toInt() - n );
            return *this;
        }

        n *= nsign;
        int carry = 0;
        int i;
        for( i = 0; n || carry; i++ )
        {
            int dig = n % 10;
            int newdig = digits[i] - dig + carry;
            if( newdig < 0 ) newdig += 10, carry = -1;
            else carry = 0;
            digits[i] = newdig;
            n /= 10;
        }
        normalize();
    }
    else operator+=( -n );
    return *this;
}

BigInt &BigInt::operator-=( BigInt n )
{
    int maxS = max( size, n.size ) + 1;
    while( maxS >= capacity ) grow();        //FIXME: this is stupid

    if( !n.sign ) return *this;
    if( !sign ) sign = 1;
    if( sign == n.sign )
    {
        if( sign >= 0 && *this < n || sign < 0 && *this > n )
        {
            // Subtracting a bigger number
            BigInt tmp = n;
            tmp -= *this;
            *this = tmp;
            sign = -sign;
            return *this;
        }

        int carry = 0;
        int i;
        for( i = 0; i < maxS - 1; i++ )
        {
            int newdig = carry;
            if( i < size ) newdig += digits[i];
            if( i < n.size ) newdig -= n.digits[i];
            if( newdig < 0 ) newdig += 10, carry = -1;
            else carry = 0;
            digits[i] = newdig;
        }
        if( carry )     // Subtracted a bigger number, need to flip sign
        {
            if( i ) digits[0] = 10 - digits[0];
            size = ( i ? 1 : 0 );
            for( int j = 1; j < i; j++ )
            {
                digits[j] = 9 - digits[j];
                if( digits[i] ) size = j + 1;
            }
            sign *= -1;
        }
        normalize();
    }
    else
    {
        n.sign *= -1;
        operator+=( n );
        n.sign *= -1;
    }
    return *this;
}

BigInt BigInt::operator*( int n )
{
    BigInt result( 0, size + ( int )sizeof( n ) * 8 );
    int nsign = sig( n );
    n *= nsign;
    result.sign = sign * nsign;
    if( !result.sign ) return result;

    int i, j;
    for( i = 0; n; i++ )
    {
        int dig = n % 10;
        if( dig )
        {
            int carry = 0;
            for( j = 0; j < size || carry; j++ )
            {
                int newDig = result.digits[i + j] + ( j < size ? dig * digits[j] : 0 ) + carry;
                result.digits[i + j] = newDig % 10;
                carry = newDig / 10;
            }
        }
        n /= 10;
    }
    result.size = i + j - 1;
    return result;
}

BigInt BigInt::operator*( BigInt n )
{
    BigInt result( 0, size + n.size );

    result.sign = sign * n.sign;
    if( !result.sign ) return result;

    int i, j;
    for( i = 0; i < n.size; i++ )
    {
        if( n.digits[i] )
        {
            int carry = 0;
            for( j = 0; j < size || carry; j++ )
            {
                int newDig =
                    result.digits[i + j] +
                    ( j < size ? n.digits[i] * digits[j] : 0 ) +
                    carry;
                result.digits[i + j] = newDig % 10;
                carry = newDig / 10;
            }
        }
    }
    result.size = i + j - 1;

    return result;
}

void BigInt::operator*=( int n )
{
    operator=( operator*( n ) );
}

void BigInt::operator*=( BigInt n )
{
    operator=( operator*( n ) );
}

BigInt BigInt::operator/( int n )
{
    if( !n ) n /= n;        //XXX: force a crash

    BigInt result( *this );
    result /= n;
    return result;
}

BigInt BigInt::operator/( BigInt n )
{
    if( !n ) n.size /= n.size;       //XXX: force a crash

    BigInt result( *this );
    result /= n;
    return result;
}

void BigInt::operator/=( int n )
{
    divide( n );
}

void BigInt::operator/=( BigInt n )
{
    divide( n );
}

int BigInt::operator%( int n )
{
    BigInt tmp( *this );
    return tmp.divide( n );
}

void BigInt::operator%=( int n )
{
    operator=( divide( n ) );
}

BigInt BigInt::operator%( BigInt n )
{
    BigInt tmp( *this );
    return tmp.divide( n );
}

void BigInt::operator%=( BigInt n )
{
    operator=( divide( n ) );
}

int BigInt::divide( int n )
{
    if( !n ) n /= n;        //XXX: force a crash

    int nsign = sig( n );
    n *= nsign;
    if( !sign ) return 0;
    sign *= nsign;

    int tmp = 0;
    for( int i = size - 1; i >= 0; i-- )
    {
        tmp *= 10;
        tmp += digits[i];
        digits[i] = tmp / n;
        tmp -= digits[i] * n;
    }
    normalize();
    return tmp;
}

BigInt BigInt::divide( BigInt n )
{
    if( !n ) n.size /= n.size;         //XXX: force a crash

    if( !sign ) return 0;
    sign *= n.sign;

    int oldSign = n.sign;
    n.sign = 1;

    BigInt tmp( 0, size );
    for( int i = size - 1; i >= 0; i-- )
    {
        tmp *= 10;
        tmp += digits[i];
        digits[i] = 0;
        while( tmp >= n ) { tmp -= n; digits[i]++; }
    }
    normalize();

    n.sign = oldSign;

    return tmp;
}

// This is only exact to the first 15 or so digits, but it is
// never an over-estimate
BigInt BigInt::operator*( long double n )
{
    // the number of digits after the decimal point to use
    int DIGS_AFTER_DOT = 15;

    int nsign = sig( n );
    n *= nsign;
    int ndigs = n >= 1 ? ( int )log10( n ) + 1 : 0;
    BigInt result( 0, size + ndigs );
    result.sign = sign * nsign;
    if( !result.sign ) return result;

    if( n >= 1 ) for( int i = 0; i < ndigs; i++ ) n /= 10;
    result.size = 0;

    char afterDot[DIGS_AFTER_DOT + 1];
    memset( afterDot, 0, sizeof( afterDot ) );

    // Keep going until the DIGS_AFTER_DOT'th digit after the decimal point
    for( int i = ndigs - 1; i >= -DIGS_AFTER_DOT; i-- )
    {
        n *= 10;
        int dig = ( int )floor( n );
        n -= dig;
        if( !dig ) continue;

        int carry = 0;
        for( int j = 0; j < size || carry; j++ )
        {
            int newdig =
                ( i + j < 0 ? afterDot[-( i + j )] : result.digits[i + j] )
                + dig * digits[j]
                + carry;
            ( i + j < 0 ? afterDot[-( i + j )] : result.digits[i + j] ) = newdig % 10;
         //   if( i + j >= 0 && result.digits[i + j] ) result.size >?= i + j + 1;
            carry = newdig / 10;
        }
    }
    if( !result.size ) result.sign = 0;
    return result;
}

void BigInt::operator*=( long double n )
{
    operator=( operator*( n ) );
}

BigInt BigInt::operator<<( int n )
{
    BigInt result( *this );
    result <<= n;
    return result;
}

void BigInt::operator<<=( int n )
{
    if( n < 0 ) operator>>=( -n );
    else if( n > 0 )
    {
        BigInt mult( 1, 4 * n );
        for( int i = ( 1 << 30 ); i; i >>= 1 )
        {
            mult *= mult;
            if( n & i ) mult *= 2;
        }
        operator*=( mult );
    }
}

BigInt BigInt::operator>>( int n )
{
    BigInt result( *this );
    result >>= n;
    return result;
}

void BigInt::operator>>=( int n )
{
    if( n < 0 ) operator<<=( -n );
    else if( n > 0 )
    {
        BigInt mult( 1, 4 * n );
        for( int i = ( 1 << 30 ); i; i >>= 1 )
        {
            mult *= mult;
            if( n & i ) mult *= 2;
        }
        operator/=( mult );
    }
}
/*
BigInt BigInt::operator&( int n )
{
}

BigInt BigInt::operator&( BigInt n )
{
}

void BigInt::operator&=( int n )
{
}

void BigInt::operator&=( BigInt n )
{
}

BigInt BigInt::operator|( int n )
{
}

BigInt BigInt::operator|( BigInt n )
{
}

void BigInt::operator|=( int n )
{
}

void BigInt::operator|=( BigInt n )
{
}

BigInt BigInt::operator^( int n )
{
}

BigInt BigInt::operator^( BigInt n )
{
}

void BigInt::operator^=( int n )
{
}

void BigInt::operator^=( BigInt n )
{
}

BigInt BigInt::operator~()
{
}
*/
BigInt BigInt::operator,( int n )
{
    BigInt result( 0, size + ( int )sizeof( n ) * 8 );
    for( result.size = 0; n; result.size++ )
    {
        result.digits[result.size] = n % 10;
        n /= 10;
    }
    memcpy( result.digits + result.size, digits, size * sizeof( digits[0] ) );
    result.size += size;
    result.sign = 1;
    result.normalize();
    return result;
}

BigInt BigInt::operator,( BigInt n )
{
    BigInt result( 0, size + n.size );
    memcpy( result.digits, n.digits, n.size * sizeof( n.digits[0] ) );
    memcpy( result.digits + n.size, digits, size * sizeof( digits[0] ) );
    result.size = size + n.size;
    result.sign = 1;
    result.normalize();
    return result;
}

bool BigInt::operator!()
{
    return !size;
}

BigInt::operator bool()
{
    return size;
}

//BigInt::operator int()
//{
//    return toInt();
//}

BigInt::operator string()
{
    return toString();
}

bool BigInt::operator<( BigInt n )
{
    return( compare( n ) < 0 );
}

bool BigInt::operator>( BigInt n )
{
    return( compare( n ) > 0 );
}

bool BigInt::operator==( BigInt n )
{
    return( compare( n ) == 0 );
}

bool BigInt::operator<=( BigInt n )
{
    return( compare( n ) <= 0 );
}

bool BigInt::operator>=( BigInt n )
{
    return( compare( n ) >= 0 );
}

bool BigInt::operator<( int n )
{
    return( compare( BigInt( n ) ) < 0 );
}

bool BigInt::operator>( int n )
{
    return( compare( BigInt( n ) ) > 0 );
}

bool BigInt::operator==( int n )
{
    return( compare( BigInt( n ) ) == 0 );
}

bool BigInt::operator<=( int n )
{
    return( compare( BigInt( n ) ) <= 0 );
}

bool BigInt::operator>=( int n )
{
    return( compare( BigInt( n ) ) >= 0 );
}

int BigInt::compare( BigInt n )
{
    if( sign < n.sign ) return -1;
    if( sign > n.sign ) return 1;
    if( size < n.size ) return -sign;
    if( size > n.size ) return sign;
    for( int i = size - 1; i >= 0; i-- )
    {
        if( digits[i] < n.digits[i] ) return -sign;
        else if( digits[i] > n.digits[i] ) return sign;
    }
    return 0;
}


BigInt dp[70][2][2][2][70];
bool V[70][2][2][2][70] ;


string i2b(ll a) { string str = ""; do {str += (a&1)+'0';a >>= 1;}while(a);reverse(all(str)); return str; }


string Str ;
int N ;

BigInt solve(int pos , bool hasSmall , bool start , bool prev , int countOne )
{
       if(pos == N) return BigInt(countOne);
       BigInt &ret = dp[ pos ][ hasSmall ][ start ][ prev ][ countOne ];
       if( V[ pos ][ hasSmall ][ start ][ prev ][ countOne ]) return ret;
       V[ pos ][ hasSmall ][ start ][ prev ][ countOne ] = true ;
       int lim = hasSmall ? 1 : Str[pos] - '0'; ret = 0;
       if(start) {
              For(i,lim) ret += solve( pos + 1 , hasSmall || ( i < lim ) , false , true , countOne + ( i == 1 && prev) ); // placing 0
              ret += solve( pos + 1 , true , true ,false, 0 );
       }
       else {
              forab(i,0,lim) ret += solve( pos + 1 , hasSmall || ( i < lim ) , false , i , countOne + (i == 1 && prev ) );
       }
       return ret;
}


int main(){
    //freopen("in.txt","r",stdin);
    int cs = 1 ;
    ll a ;
    while( cin >> a ) {
        if( a < 0 ) break ;
        Str = i2b(a);
       // cout << Str << endl;
      //  cout << a << endl << Str << "     " << Str.size() << endl ;
        N = Str.size();
        ms(V,false);
        BigInt ret = solve(0,false,true,false,0);
        printf("Case %d: ",cs++);
        cout << ret << endl;
    }
}
