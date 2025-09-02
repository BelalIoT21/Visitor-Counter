# Visitor Counter

A simple, efficient, and customizable visitor counter application that tracks and displays the number of visitors to your website, GitHub profile, or physical location. This project provides real-time visitor tracking with persistent data storage and easy integration.

## 🚀 Features

- **Real-time Counting**: Instant visitor tracking and display
- **Persistent Storage**: Data retention across server restarts
- **Customizable Display**: Various counter styles and themes
- **API Integration**: RESTful API for external access
- **Analytics Dashboard**: Detailed visitor statistics and trends
- **Multi-platform Support**: Web, mobile, and IoT device compatible
- **Lightweight**: Minimal resource usage and fast response times
- **Security**: IP filtering and bot detection capabilities

## 📋 Table of Contents

- [Installation](#installation)
- [Quick Start](#quick-start)
- [Configuration](#configuration)
- [API Reference](#api-reference)
- [Customization](#customization)
- [Deployment](#deployment)
- [Contributing](#contributing)
- [License](#license)


## 📥 Installation

### Prerequisites
- Node.js (v14 or higher)
- npm or yarn package manager
- Database (MongoDB/MySQL/SQLite)

### Method 1: Clone from GitHub
```bash
git clone https://github.com/BelalIoT21/Visitor-Counter.git
cd Visitor-Counter
npm install
```

### Method 2: npm Installation
```bash
npm install visitor-counter-app
```

### Method 3: Docker Installation
```bash
docker pull belal/visitor-counter
docker run -p 3000:3000 belal/visitor-counter
```

## 🚀 Quick Start

### Basic Setup
```bash
# Install dependencies
npm install

# Configure environment variables
cp .env.example .env
# Edit .env with your configuration

# Run the application
npm start
```

### Environment Configuration
Create a `.env` file in the root directory:
```env
PORT=3000
DATABASE_URL=mongodb://localhost:27017/visitor_counter
SESSION_SECRET=your-secret-key
ENABLE_ANALYTICS=true
MAX_REQUESTS_PER_HOUR=1000
```

### Basic Usage Example
```javascript
const VisitorCounter = require('./visitor-counter');

// Initialize counter
const counter = new VisitorCounter({
    database: 'mongodb://localhost:27017/visitors',
    enableAnalytics: true
});

// Start the server
counter.start(3000, () => {
    console.log('Visitor Counter running on port 3000');
});
```

## ⚙️ Configuration

### Database Options
```javascript
// MongoDB Configuration
const mongoConfig = {
    type: 'mongodb',
    url: 'mongodb://localhost:27017/visitor_counter',
    options: {
        useNewUrlParser: true,
        useUnifiedTopology: true
    }
};

// SQLite Configuration
const sqliteConfig = {
    type: 'sqlite',
    database: './visitors.db'
};

// MySQL Configuration
const mysqlConfig = {
    type: 'mysql',
    host: 'localhost',
    port: 3306,
    username: 'root',
    password: 'password',
    database: 'visitor_counter'
};
```

### Counter Customization
```javascript
const counterOptions = {
    // Display options
    theme: 'modern',           // 'classic', 'modern', 'minimal'
    showTodayCount: true,      // Show today's visitor count
    showOnlineCount: true,     // Show current online visitors
    showTotalCount: true,      // Show total visitor count
    
    // Behavior options
    countUniqueOnly: false,    // Count only unique visitors
    sessionTimeout: 1800,     // Session timeout in seconds
    ignoreReturning: false,    // Ignore returning visitors
    
    // Security options
    enableBotDetection: true,  // Filter out bots
    enableIPFiltering: true,   // Enable IP-based filtering
    rateLimiting: {
        enabled: true,
        maxRequests: 100,      // Max requests per hour
        timeWindow: 3600       // Time window in seconds
    }
};
```

## 📊 API Reference

### Get Visitor Count
```http
GET /api/visitors/count
```

**Response:**
```json
{
    "total": 12345,
    "today": 234,
    "online": 12,
    "timestamp": "2024-01-15T10:30:00Z"
}
```

### Get Visitor Analytics
```http
GET /api/visitors/analytics?period=7d
```

**Response:**
```json
{
    "period": "7d",
    "data": [
        {"date": "2024-01-09", "count": 150},
        {"date": "2024-01-10", "count": 180},
        {"date": "2024-01-11", "count": 200}
    ],
    "total": 1250,
    "average": 178.6
}
```

### Reset Counter
```http
POST /api/visitors/reset
Authorization: Bearer your-admin-token
```

### Export Data
```http
GET /api/visitors/export?format=csv
Authorization: Bearer your-admin-token
```

## 🎨 Customization

### Custom Themes
Create custom CSS themes in `/themes/` directory:

```css
/* themes/custom.css */
.visitor-counter {
    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
    border-radius: 12px;
    padding: 20px;
    color: white;
    text-align: center;
    box-shadow: 0 8px 32px rgba(0,0,0,0.1);
}

.counter-number {
    font-size: 2.5em;
    font-weight: bold;
    margin: 10px 0;
}
```

### Widget Integration
Add to your HTML:
```html
<!-- Simple Counter Widget -->
<div id="visitor-counter"></div>
<script src="https://your-domain.com/widget.js"></script>
<script>
    VisitorCounter.init({
        elementId: 'visitor-counter',
        apiUrl: 'https://your-api-url.com',
        theme: 'modern'
    });
</script>
```

### GitHub Profile Integration
Add to your GitHub profile README:
```markdown
![Visitor Count](https://your-counter-url.com/count.svg)
```

## 🚀 Deployment

### Heroku Deployment
```bash
# Login to Heroku
heroku login

# Create Heroku app
heroku create your-visitor-counter

# Set environment variables
heroku config:set DATABASE_URL=your-database-url
heroku config:set SESSION_SECRET=your-secret

# Deploy
git push heroku main
```

### Vercel Deployment
```bash
# Install Vercel CLI
npm i -g vercel

# Deploy
vercel --prod
```

### Docker Deployment
```dockerfile
FROM node:16-alpine

WORKDIR /app
COPY package*.json ./
RUN npm ci --only=production

COPY . .
EXPOSE 3000

CMD ["npm", "start"]
```

### Nginx Configuration
```nginx
server {
    listen 80;
    server_name your-domain.com;

    location / {
        proxy_pass http://localhost:3000;
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection 'upgrade';
        proxy_set_header Host $host;
        proxy_cache_bypass $http_upgrade;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
    }
}
```

## 🏗️ Project Structure

```
Visitor-Counter/
├── src/
│   ├── controllers/
│   │   └── visitorController.js
│   ├── models/
│   │   └── Visitor.js
│   ├── routes/
│   │   └── api.js
│   ├── middleware/
│   │   ├── auth.js
│   │   └── rateLimiter.js
│   └── utils/
│       ├── database.js
│       └── analytics.js
├── public/
│   ├── css/
│   ├── js/
│   └── themes/
├── views/
│   ├── dashboard.ejs
│   └── counter.ejs
├── config/
│   └── database.js
├── tests/
├── docker-compose.yml
├── Dockerfile
├── package.json
└── README.md
```

## 🧪 Testing

### Run Tests
```bash
# Run all tests
npm test

# Run with coverage
npm run test:coverage

# Run specific test file
npm test -- --grep "visitor counter"
```

### Test Example
```javascript
const request = require('supertest');
const app = require('../src/app');

describe('Visitor Counter API', () => {
    it('should return current visitor count', async () => {
        const response = await request(app)
            .get('/api/visitors/count')
            .expect(200);
            
        expect(response.body).toHaveProperty('total');
        expect(response.body).toHaveProperty('today');
        expect(response.body).toHaveProperty('online');
    });
});
```

## 📈 Performance

### Metrics
- **Response Time**: < 50ms average
- **Throughput**: 1000+ requests/second
- **Memory Usage**: < 50MB
- **Database Size**: Optimized for millions of records

### Optimization Tips
- Enable database indexing on frequently queried fields
- Use Redis for session storage in production
- Implement CDN for static assets
- Enable gzip compression
- Use connection pooling for database connections

## 🤝 Contributing

We welcome contributions from the community!

### How to Contribute
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Development Setup
```bash
# Clone your fork
git clone https://github.com/yourusername/Visitor-Counter.git

# Install dependencies
npm install

# Run in development mode
npm run dev

# Run tests
npm test
```

### Code Style
- Follow ESLint configuration
- Use Prettier for code formatting
- Add tests for new features
- Update documentation as needed

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

```
MIT License

Copyright (c) 2024 Belal IoT

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
```

## 🙏 Acknowledgments

- [Express.js](https://expressjs.com/) - Web framework
- [MongoDB](https://www.mongodb.com/) - Database solution
- [Chart.js](https://www.chartjs.org/) - Analytics visualization
- [Socket.IO](https://socket.io/) - Real-time communication
- Community contributors and testers

## 📞 Contact

**Developer**: Belal IoT  
**GitHub**: [@BelalIoT21](https://github.com/BelalIoT21)  
**Email**: [Contact through GitHub]

### Support
- 🐛 **Bug Reports**: [GitHub Issues](https://github.com/BelalIoT21/Visitor-Counter/issues)
- 💡 **Feature Requests**: [GitHub Discussions](https://github.com/BelalIoT21/Visitor-Counter/discussions)
- 📖 **Documentation**: [Wiki](https://github.com/BelalIoT21/Visitor-Counter/wiki)

---

⭐ **Star this repository if it helped you!**

*Made with ❤️ by Belal IoT*
