defmodule InClass.Repo do
  use Ecto.Repo,
    otp_app: :inClass,
    adapter: Ecto.Adapters.Postgres
end
