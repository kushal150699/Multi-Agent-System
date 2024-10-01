class NavigationPath:
    def _init_(self, visitor_id, host_id, path):
        self.visitor_id = visitor_id
        self.host_id = host_id
        self.path = path

class AccessDenied:
    def _init_(self, visitor_id, reason):
        self.visitor_id = visitor_id
        self.reason = reason

class OutOfService:
    def _init_(self, duration):
        self.duration = duration