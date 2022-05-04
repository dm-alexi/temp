class ValidationError(Exception):
    def __init__(self, message: str = 'unknown error'):
        super().__init__(f'Validation error: {message}')


class InvalidExpressionError(ValidationError):
    def __init__(self, expr: str):
        super().__init__(f'Invalid or redundant expression "{expr}" in the equation')


class UnsupportedExponentError(ValidationError):
    def __init__(self, exp: float):
        super().__init__(f'Unsupported exponent "{exp}" in the equation')
