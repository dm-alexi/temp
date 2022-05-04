import re

from .ft_math import ft_abs, ft_sqrt, ft_convert
from .errors import ValidationError, InvalidExpressionError, UnsupportedExponentError


class Tokenizer:
    @staticmethod
    def tokenize(line: str):
        line = ''.join(line.split())
        if line and line[0] not in '+-':
            line = '+' + line
        patterns = r'([+-](?:\d+(?:\.\d+)?\*?)?X(?:\^\-?\d+(?:\.\d+)?)?)|([+-]\d+(?:\.\d+)?)'
        tokens = re.split(patterns, line, flags=re.IGNORECASE)
        return [x for x in tokens if x]

    @staticmethod
    def to_dict(line: str):
        pool = {0: 0}
        for token in Tokenizer.tokenize(line):
            if re.fullmatch(r'[+-]\d+(?:\.\d+)?', token):
                pool[0] += ft_convert(token)
            elif m := re.fullmatch(r'([+-])(?:(\d+(?:\.\d+)?)\*?)?X(?:\^(-?\d+(?:\.\d+)?))?', token,
                                   flags=re.IGNORECASE):
                factor1 = ft_convert(m[1] + ('1' if m[2] is None else m[2]))
                factor2 = 1 if m[3] is None else ft_convert(m[3])
                if factor1 != 0:
                    pool[factor2] = pool.get(factor2, 0) + factor1
            else:
                raise InvalidExpressionError(token)
        return pool


class Solver:
    """
    Class Solver operates and solves quadratic equations
    """
    types = ['identity', 'constant', 'linear', 'quadratic', 'cubic', 'quadric', 'quintic', 'sextic', 'septic',
             'high-order']

    def __init__(self, line: str):
        self.initial = line.strip()
        self.terms = None
        self.type = None
        self.reduced = None
        self.degree = None
        self.roots = None
        self.result = None
        self._solve()

    def _solve(self):
        try:
            self._validate()
        except ValidationError as e:
            self.result = str(e)
            return
        self.type = Solver.types[min(self.degree, 7) + 1]
        if self.degree == -1:
            self.result = 'Each number is a solution'
        elif self.degree == 0:
            self.result = 'There are no solutions'
        elif self.degree == 1:
            self._solve_linear()
        elif self.degree == 2:
            self._solve_quadratic()
        else:
            self.result = f'This software does not solve {self.type} equations'

    def _reduce(self, power, factor):
        res = '' if power == self.degree else '+ ' if factor > 0 else '- '
        if ft_abs(factor) != 1 or power == 0:
            res += str(ft_abs(factor))
        if power != 0:
            if ft_abs(factor) != 1:
                res += ' * '
            res += f'x^{power}' if power != 1 else 'x'
        return res

    def _validate(self):
        equation = self.initial.split('=')
        if len(equation) != 2:
            raise ValidationError('Equation must contain exactly one "=" symbol')
        if not equation[0] or not equation[1]:
            raise ValidationError('A part of the equation is missing')
        l, r = Tokenizer.to_dict(equation[0]), Tokenizer.to_dict(equation[1])
        self.terms = {k: l.get(k, 0) - r.get(k, 0) for k in
                      set(l.keys()).union(set(r.keys())) if l.get(k, 0) != r.get(k, 0)}
        if not self.terms:
            self.degree = -1
            self.reduced = '0 = 0'
            return
        self.degree = max(self.terms.keys())
        if self.terms[self.degree] < 0:
            self.terms = {k: -v for k, v in self.terms.items()}
        self.reduced = ' '.join((self._reduce(k, v) for k, v in sorted(self.terms.items(), reverse=True))) + ' = 0'
        for exp in self.terms.keys():
            if exp < 0 or int(exp) != exp:
                raise UnsupportedExponentError(exp)

    def _solve_linear(self):
        self.roots = (str(-self.terms.get(0, 0) / self.terms.get(1, 0)), )
        self.result = f'There is one solution:'

    def _solve_quadratic(self):
        a, b, c = self.terms.get(2, 0), self.terms.get(1, 0), self.terms.get(0, 0)
        d = b * b - 4 * a * c
        if d > 0:
            self.result = f'Discriminant is strictly positive ({d}), there are two real solutions:'
            self.roots = (str((-b + ft_sqrt(d)) / (2 * a)), str((-b - ft_sqrt(d)) / (2 * a)))
        elif d < 0:
            self.result = f'Discriminant is strictly negative ({d}), there are two complex solutions:'
            self.roots = (f'{-b / (2 * a)} + {ft_sqrt(ft_abs(d)) / (2 * a)}i',
                          f'{-b / (2 * a)} - {ft_sqrt(ft_abs(d)) / (2 * a)}i')
        else:
            self.result = f'Discriminant is zero, there is one solution:'
            self.roots = (str(-b / (2 * a)), )

    def __repr__(self):
        return f'Initial equation: {self.initial}\n' \
               f'Reduced form: {self.reduced}\n' \
               f'Polynomial degree: {self.degree}\n' \
               f'Polynomial type: {self.type}\n' \
               f'{self.result}\n' \
               f'{", ".join(self.roots) if self.roots else ""}'
