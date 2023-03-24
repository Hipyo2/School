defmodule Cs491Hm1.Application do
  # See https://hexdocs.pm/elixir/Application.html
  # for more information on OTP Applications
  @moduledoc false

  use Application

  @impl true
  def start(_type, _args) do
    children = [
      # Start the Ecto repository
      Cs491Hm1.Repo,
      # Start the Telemetry supervisor
      Cs491Hm1Web.Telemetry,
      # Start the PubSub system
      {Phoenix.PubSub, name: Cs491Hm1.PubSub},
      # Start the Endpoint (http/https)
      Cs491Hm1Web.Endpoint
      # Start a worker by calling: Cs491Hm1.Worker.start_link(arg)
      # {Cs491Hm1.Worker, arg}
    ]

    # See https://hexdocs.pm/elixir/Supervisor.html
    # for other strategies and supported options
    opts = [strategy: :one_for_one, name: Cs491Hm1.Supervisor]
    Supervisor.start_link(children, opts)
  end

  # Tell Phoenix to update the endpoint configuration
  # whenever the application is updated.
  @impl true
  def config_change(changed, _new, removed) do
    Cs491Hm1Web.Endpoint.config_change(changed, removed)
    :ok
  end
end
