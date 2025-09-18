FROM postgres:latest

# Set environment variables
ENV POSTGRES_PASSWORD=postgres

# Expose the default PostgreSQL port
EXPOSE 5432

# Modify postgresql.conf to allow listening on all interfaces
RUN echo "listen_addresses='*'" >> /etc/postgresql/postgresql.conf

# Add custom pg_hba.conf to allow connections from any IP address
RUN echo "host all all 0.0.0.0/0 md5" > /etc/postgresql/pg_hba.conf
RUN echo "host all all ::/0 md5" >> /etc/postgresql/pg_hba.conf


COPY init.sql /docker-entrypoint-initdb.d/


